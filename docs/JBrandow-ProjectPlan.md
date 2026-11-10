# Virus Spread Lab — Project Plan

## Problem and purpose

The program models a simplified outbreak moving through a fixed grid of people. The purpose is to make transmission, recovery time, and outbreak momentum easier to see in a console application. It uses classroom assumptions and does not represent real-world public-health data.

## Minimum version that must work first

The minimum version is a console program that starts, accepts a menu choice, seeds a small number of infected people, advances the simulation for a requested number of days, and prints a final summary without crashing. The completed foundation goes beyond that minimum by also showing the grid, validating input, comparing profiles, and explaining the model.

## Core features

1. **Run an outbreak simulation:** choose a profile, number of days, and starting infected count, then view daily results.
2. **Compare profiles:** run the same initial conditions through the available illustrative profiles and display a summary table.
3. **Explain the model:** show the state symbols, contact behavior, recovery rule, spread-factor definition, and classroom-use warning.
4. **Validate menu input:** reject values outside the allowed range and recover from non-numeric input.

## Class plan

### `Person`

Stores one person’s health state and infection age. It owns the state transitions for becoming infected, advancing an infection, and recovering.

### `VirusProfile`

Stores the settings for one illustrative profile: contacts per day, transmission chance, recovery days, name, and description. It exposes read-only getters so the simulation can use the settings without owning profile-editing logic.

### `Simulation`

Owns the grid of `Person` objects, the random-number generator, daily transitions, neighbor lookup, grid display, and summary statistics. It coordinates the other classes but does not duplicate their state-transition responsibilities.

### Main program

Builds the profile list, displays the menu, validates input, and connects user choices to the `Simulation` interface. The simulation rules stay outside `main()`.

## Data structures

- `std::vector<Person>` stores the grid in row-major order.
- `std::vector<VirusProfile>` stores the selectable profiles.
- `std::mt19937` and standard distributions provide seeded, repeatable simulation behavior.
- `SimulationSummary` stores final counts and peak infection information for comparison output.
- `enum class HealthState` prevents health states from being represented by unexplained integers.

## User interaction

The application is menu-driven. A user selects an activity, enters bounded numeric settings when needed, reads the report, and presses Enter to return to the menu. Invalid input is cleared and requested again rather than terminating the program.

## Design decisions

The code is split into headers and implementation files so each class has a clear responsibility. The grid dimensions are constants on `Simulation`, and the profile values are kept in one creation function in the console program. This keeps the first milestone understandable while leaving room for later additions such as exports and repeatable scenario controls.

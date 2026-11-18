# Milestone 4 — Final Development Notes

## Features Completed

- Grid-based outbreak simulation with daily susceptible, infected, recovered, and new-infection reporting.
- Separate Person, VirusProfile, and Simulation classes.
- Three illustrative transmission profiles for comparison.
- Quick Run defaults, optional repeatable seeds, and optional outbreak_report.txt export.
- Clear menu navigation, a model-explanation screen, and replay behavior.
- Line-based input validation with specific error messages.
- Pointer-based access to the selected virus profile.

## Refactoring and Code Improvements

The interactive simulation flow was reorganized so settings-dependent operations remain inside the replay loop where their values are valid. Numeric input uses std::getline and std::stoi with separate handling for invalid and out-of-range input. Simulation responsibilities remain in the existing classes instead of being mixed into the menu code.

## Bugs Resolved

The known compilation problem caused by variables being used outside the scope of the replay loop was corrected. Seed selection and optional result export now occur in the same scope as the selected profile, day count, and starting population. Invalid input returns to the prompt without leaving the stream in a failed state.

## Usability Improvements

Every numeric prompt states the allowed range. Invalid input explains what went wrong. The Help screen explains the grid symbols, daily transmission behavior, recovery timing, and the limits of the classroom model. Quick Run and replay options make it easier to explore the simulation.

## Final Testing Plan

The final test pass covers compilation, each main-menu branch, invalid numeric input, invalid yes/no input, a short simulation, a longer simulation, repeatable seeds, report export, profile comparison, the Help screen, replay, and clean exit. The Visual Studio solution and build steps remain documented in the project README.

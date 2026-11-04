# Milestone 2: Planning Worksheet
**Student:** Jason Brandow  
**Project:** Virus Spread Lab  
**Date:** November 4, 2026

---

## 1. Current Project Overview

Virus Spread Lab is a C++ console simulation that shows how a virus can spread across a grid of people. Each person can be susceptible, infected, or recovered. The program has three illustrative profiles (common-cold style, seasonal-flu style, and high-transmission style), a live grid view, daily statistics, a spread-factor metric, a profile comparison mode, and an explanation screen.

Current classes:
- `Person` – tracks health state and how long someone has been infected
- `VirusProfile` – holds contacts per day, transmission chance, and recovery days
- `Simulation` – manages the grid, daily steps, reporting, and summary stats
- Main menu with input validation

---

## 2. Inspiration & Research

I looked at simple SIR-style models and other educational console simulations. Most of them use a grid or list of agents, random contacts, and a basic susceptible/infected/recovered cycle. I also checked how other student projects handle menus and daily reports so the output stays readable in the console.

Key things that work well:
- Clear visual difference between states (dot, #, +)
- Daily summary numbers so you can see the curve without staring at the grid the whole time
- Preset profiles instead of making the user type every parameter every run

---

## 3. Planned Features for This Week

### Feature 1: Repeatable Scenario Seeds
- Let the user enter a seed number (or pick from a few saved seeds)
- Same seed + same profile = same outbreak every time
- Useful for comparing changes and for the progress video

### Feature 2: Exportable Results
- After a simulation finishes, offer to save a simple text report (peak infected, final recovered, day-by-day counts)
- Write it to a `.txt` file in the project folder

### Feature 3: Improved Usability
- Add a “quick run” option that uses default days and starting cases so you don’t have to answer every prompt every time
- Clearer prompts and a short confirmation before starting a long run

### Feature 4: Basic Automated Checks (optional stretch)
- Small test functions that verify recovery timing and that the population count stays constant
- Run them from a hidden menu option or at startup in debug builds

---

## 4. System Behavior & Program Flow

**Main loop stays the same:**
1. Show banner and main menu
2. User picks:
   - Run simulation
   - Compare profiles
   - Learn how the model works
   - Exit
3. After a simulation, show summary and ask if they want to export results or run again

**New flow for seeded runs:**
- Before starting, ask “Use a specific seed? (y/n)”
- If yes, read an integer seed and pass it to `Simulation::reset`
- If no, keep using `std::random_device` like it does now

**Export flow:**
- After the daily reports finish, print the summary
- Ask “Save results to file? (y/n)”
- If yes, write a short report with the profile name, seed, peak infected, and final numbers

---

## 5. User Interaction Changes

- Add one extra prompt for seed (optional)
- Add one extra prompt for export (optional)
- Keep all existing input validation so bad input doesn’t crash
- Make the comparison table a little wider so the profile names don’t wrap

---

## 6. Class / Code Changes

- `Simulation` – already accepts a seed in `reset`; just expose it better from the menu
- Add a small helper function (or method) to write the summary to a file
- Possibly add a `getSummary()` or keep using the existing `SimulationSummary` struct
- No new classes needed right now

---

## 7. Potential Challenges

- Making sure the export file writes in the correct folder when running from Visual Studio
- Keeping the console output from getting too long on 60-day runs
- Testing that the same seed really produces the same results

---

## 8. Success Criteria for This Milestone

- User can run a simulation with a chosen seed and get the same result twice
- User can export a simple text report after a run
- Menu still validates input and doesn’t crash on bad numbers
- Planning document is complete and the video shows at least one new or improved feature working

---

*This plan will be updated as I implement the features.*

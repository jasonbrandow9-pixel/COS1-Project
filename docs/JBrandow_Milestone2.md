# Milestone 2 Documentation
**Student:** J. Brandow  
**Project:** Virus Spread Lab  
**Week:** 2

---

## Overview of Changes This Week

This week focused on expanding the existing Virus Spread Lab foundation, improving usability, and making the simulation results easier to understand.

The core class structure (Person, VirusProfile, Simulation) stayed intact. Work was done by extending those classes and improving the menu flow rather than rewriting everything.

---

## Features Added

### 1. Richer Final Summary
After a simulation finishes, the program now shows:
- Days simulated
- Peak number of infected people and the day that peak occurred
- Final infected and recovered counts
- Total people who were ever infected (with percentage of the population)
- A short plain-English reading of the outbreak (contained / moderate / high transmission)

### 2. Replay Option
After each run the user can choose to start another simulation immediately without returning to the main menu. This makes it easier to try different profiles and settings quickly.

### 3. Clearer Input Validation (Usability)
All numeric prompts now:
- State the allowed range up front
- Give a specific error message that tells the user exactly what is expected when the input is wrong

### 4. Planning Document
A full Milestone 2 planning worksheet was added under `/docs` that lists intended features, class changes, usability goals, and the development order for the week.

---

## Code Structure Updates

| File | Change |
|------|--------|
| `Simulation.h` | Added `peakDay` and `everInfected` to `SimulationSummary` |
| `Simulation.cpp` | Tracks the day of the peak, counts ever-infected, prints the new final summary |
| `COS1-Console.cpp` | Improved validation messages, added replay loop after interactive runs |
| `docs/JBrandow-Milestone2-Planning.md` | New planning worksheet |
| `docs/JBrandow_Milestone2.md` | This documentation file |

No new classes were required this week. Existing classes were extended with clear responsibilities.

---

## Usability Improvements

1. Prompts always show the valid number range.
2. Invalid input produces a clear, specific message instead of a generic error.
3. Users can re-run simulations immediately after finishing one.
4. The final summary is written in plain language so someone new to the program can understand the outcome.

---

## What Changed and Why

- **Peak day + ever-infected tracking** – makes the results more useful for comparing different virus profiles.
- **Replay loop** – reduces friction when testing multiple settings.
- **Better validation messages** – required usability improvement; helps anyone using the program for the first time.
- **Documentation** – required for the milestone and helps keep a record of decisions.

---

## Testing Notes

- All source files compile cleanly with g++ (C++17).
- Menu ranges and validation were exercised with out-of-range and non-numeric input during development.
- Summary values were checked against known short runs (small day counts and low starting infections).

---

## Next Steps (Week 3+)

Possible directions still open:
- Custom virus settings for a single run (override contacts / transmission / recovery)
- Simple quarantine or intervention toggle
- Saving and comparing multiple result snapshots
- Additional statistics or history across runs

These will be evaluated after feedback from the Week 2 stand-up and peer responses.

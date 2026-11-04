# Milestone 2 Planning Worksheet
**Student:** J. Brandow  
**Project:** Virus Spread Lab  
**Date:** November 2026

---

## 1. Project Overview (Current State)

Virus Spread Lab is a console application that models how an infection spreads through a small population grid.  
Users can choose different virus profiles, set the number of starting infections, run the simulation for a chosen number of days, and view daily reports plus a final summary.

**Current classes:**
- `Person` – tracks health state (Susceptible / Infected / Recovered) and infection age
- `VirusProfile` – holds name, description, contacts per day, transmission chance, recovery days
- `Simulation` – manages the grid, daily steps, neighbor infection, and reporting
- Main menu in `COS1-Console.cpp`

---

## 2. Features Planned for This Week

### Feature A – Stronger Input Validation & Clearer Feedback (Usability)
- Improve all menu prompts so the user always knows what range is allowed
- Add a short “help” option that explains the symbols and how the model works
- Make invalid input messages more specific instead of a generic “please enter a valid number”

### Feature B – Adjustable Simulation Settings
- Let the user change the number of contacts per day or recovery length for a custom run (without permanently changing the preset profiles)
- Add a simple “quarantine strength” option that reduces the chance of spread for a portion of the population

### Feature C – Better End-of-Run Summary
- Show peak infected day
- Show percentage of population that became infected at least once
- Show a short text interpretation (e.g. “outbreak stayed contained” vs “high transmission”)

### Feature D – Replay / Compare Improvements
- After a run, offer a quick “run again with same settings” option
- Keep the side-by-side profile comparison but make the output easier to read

---

## 3. Class / Structure Changes

| Class          | Planned Change                                      | Why |
|----------------|-----------------------------------------------------|-----|
| Person         | Already tracks infection age – keep and use more    | Needed for recovery logic |
| VirusProfile   | Add optional override values for custom runs        | Lets user experiment without new presets |
| Simulation     | Add peak-day tracking and infection-ever counter    | Better summary statistics |
| Main (menu)    | Add Help option + clearer prompts + replay loop     | Usability improvement required this week |

No brand-new classes are required this week. Existing classes will be extended.

---

## 4. Usability Improvements (Required)

1. **Clearer prompts** – every numeric question shows the allowed range.
2. **Help screen** – short explanation of what the symbols mean and how transmission works.
3. **Better error messages** – tell the user exactly what went wrong.
4. **Replay option** – after a simulation finishes, ask if the user wants to run again without returning all the way to the top menu.

These changes make the program easier for someone who has never seen it before.

---

## 5. Development Order (This Week)

1. Write this planning document and commit it.
2. Improve menu prompts and add a Help option (usability).
3. Add peak-day tracking and richer final summary.
4. Add simple custom-settings / quarantine option.
5. Add replay-after-run flow.
6. Update documentation (`JBrandow_Milestone2.md`).
7. Create / update GitHub Issues and move them on the Project board.
8. Multiple small commits throughout the week.
9. Pull Request from `dev` → `main` at the end of the week.

---

## 6. Risks / Challenges

- Making sure the grid still prints cleanly after adding more summary text.
- Keeping the code organized so each class still has a single clear responsibility.
- Testing edge cases (1 day, max population infected, zero transmission, etc.).

---

## 7. Success Criteria for Milestone 2

- At least one clear usability improvement that a new user would notice.
- At least two additional or expanded features beyond Milestone 1.
- Documentation file in `/docs` describing what changed and why.
- At least 4 meaningful commits spread across the week.
- Project board updated with the new Issues.
- Pull Request merged into `main`.

---

*This plan may change as development continues. That is expected.*

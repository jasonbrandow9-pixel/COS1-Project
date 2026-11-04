# Milestone 2: Planning Worksheet
**Student:** Jason Brandow  
**Project:** Virus Spread Lab  
**Course:** COS1 – Project & Portfolio 1  
**Date:** November 4, 2026

---

## 1. Current Project Overview

Virus Spread Lab is an interactive C++ console simulation that visualizes how relative contact frequency, transmission chance, and recovery time affect an outbreak on a fixed grid. Each cell is a `Person` who can be susceptible (`.`), infected (`#`), or recovered (`+`).

**What already works:**
- 30×14 grid (420 people)
- Three illustrative profiles (Common-cold style, Seasonal-flu style, High-transmission style)
- Live grid that updates every 5 days or when the outbreak ends
- Daily report with susceptible, infected, recovered, new infections, and spread factor
- Profile comparison mode that runs all three profiles with the same starting conditions
- Explanation screen describing the model assumptions
- Menu with validated integer input
- `Simulation::reset` already accepts a seed

**Current class responsibilities:**
- `Person` – health state + infection age, methods to infect/recover/advance
- `VirusProfile` – name, description, contactsPerDay, transmissionChance, recoveryDays
- `Simulation` – owns the vector of people, random engine, grid printing, daily step logic, summary stats
- Main file – menu loop, profile creation, user prompts, color output

---

## 2. Inspiration & Research

I looked at simple agent-based SIR models and other educational console simulations. Common patterns that work well for this kind of project:

- Grid or agent list with clear visual states
- Random neighbor contacts instead of a full contact network (keeps the code simple)
- Preset scenarios so users can compare without typing every parameter
- Daily summary numbers so the outbreak curve is easy to see
- Explicit note that the numbers are illustrative, not real medical data

I also checked how other student console projects handle long runs and file output so I don’t make the console unreadable or write files in the wrong place when launching from Visual Studio.

---

## 3. Planned Features (Detailed)

### Feature 1: Repeatable Scenario Seeds
**Goal:** Same seed + same profile + same starting infected = identical outbreak every time.

**User flow:**
1. User chooses “Run an outbreak simulation”
2. Chooses a profile
3. New prompt: “Use a specific seed? (y/n)”
4. If yes → read an integer (validated)
5. If no → use `std::random_device` as it does now
6. Pass the seed into `sim.reset(initial, seed)`

**Why it matters:** Makes testing easier, lets me demo the same outbreak twice in the progress video, and gives users a way to reproduce interesting results.

**Implementation notes:**
- `Simulation::reset` already takes the seed — no class change required
- Add a small helper in the main file to read yes/no and an integer seed
- Store the seed used so it can be printed in the summary and written to the export file

### Feature 2: Exportable Results
**Goal:** After a run, optionally save a plain-text report.

**User flow:**
1. Simulation finishes and prints the final summary
2. New prompt: “Save results to file? (y/n)”
3. If yes → write `outbreak_report.txt` (or a name that includes the profile and seed)
4. File contains:
   - Profile name and parameters
   - Seed used
   - Days run, peak infected, final infected, final recovered
   - Optional: day-by-day numbers if I decide to store them

**Implementation notes:**
- Use `<fstream>` to write the file
- Write relative to the current working directory (Visual Studio usually sets this to the project folder)
- Keep the report short so it is easy to open and read
- Print a confirmation message with the filename after writing

### Feature 3: Improved Usability
**Goal:** Reduce friction for repeated runs.

- Add a “Quick run” menu option that uses defaults (profile 2, 30 days, 3 initial infected, random seed)
- Before a long run (>30 days), show a one-line confirmation
- After any simulation, offer “Run again with same settings?”
- Widen the comparison table slightly so profile names do not wrap

### Feature 4: Basic Sanity Checks (stretch)
**Goal:** Catch simple logic errors early.

- Small function that runs a 1-day simulation and checks that population count never changes
- Another check that an infected person recovers on the exact day given by the profile
- Can be called from a hidden menu option (e.g., choice 9) or at the start of a debug build

---

## 4. System Behavior & Detailed Program Flow

**Updated main menu:**
```
1. Run an outbreak simulation
2. Quick run (defaults)
3. Compare illustrative profiles
4. Learn how the model works
5. Exit
```

**Run simulation path:**
1. Choose profile (1–3)
2. Ask for days (1–60) and initial infected (1–10)
3. Ask for seed (optional)
4. Create Simulation, call reset with seed, call run with showDailyReport = true
5. Print final summary
6. Ask to export
7. Ask to run again with same settings or return to menu

**Comparison path:** stays mostly the same, but I will also print the seed used for each profile so the results are reproducible.

**Edge cases to handle:**
- User enters non-numeric input → existing validation already clears and re-prompts
- User asks for more initial infected than population → already limited to 10
- Outbreak dies out early → current code already breaks the day loop when infected == 0
- File write fails → print an error message and continue

---

## 5. User Interaction Changes

- One new yes/no prompt for seed
- One new yes/no prompt for export
- One new menu option for quick run
- All new prompts will use the same validated input style already in the program
- Color coding stays the same (cyan headers, yellow section titles, red for infected/#, etc.)

---

## 6. Class / Code Changes (Specific)

| File | Change |
|------|--------|
| `COS1-Console.cpp` | Add seed prompt, export prompt, quick-run option, file-writing helper |
| `Simulation.h` / `.cpp` | No major changes required; seed already supported. May add a method to return the last seed used if I want it cleaner. |
| `Person` / `VirusProfile` | No changes planned |

**New helper functions (in the anonymous namespace of the main file):**
- `bool readYesNo()`
- `unsigned int readSeed()`
- `void exportResults(const SimulationSummary&, const VirusProfile&, unsigned int seed)`

---

## 7. Potential Challenges & Mitigations

| Challenge | Mitigation |
|-----------|------------|
| File writes to the wrong folder when launched from Visual Studio | Print the full path after writing; test from both the IDE and a command prompt |
| Console floods on 60-day runs | Already only reprint the grid every 5 days; keep that behavior |
| Same seed does not reproduce | Verify by running twice with the same seed and comparing the first 5 days of output |
| Scope creep | Stick to the four features listed; move anything else to a later week |

---

## 8. Testing Plan

1. Run the same seed + profile twice and confirm the daily numbers match.
2. Export a report and open the text file to verify the numbers.
3. Try bad input (letters, numbers out of range) on every new prompt.
4. Run a quick-run and a full custom run back-to-back.
5. Confirm the comparison table still lines up after any formatting tweaks.

---

## 9. Success Criteria for This Milestone

- [ ] User can choose a seed and get identical results on repeated runs
- [ ] User can export a readable text report after a simulation
- [ ] Quick-run option works with sensible defaults
- [ ] All new prompts validate input and do not crash
- [ ] Planning document is complete and the progress video shows at least the seed or export feature working
- [ ] Repository is updated with the latest code and this document

---

## 10. Next Steps After This Plan

1. Implement the seed prompt and verify reproducibility.
2. Add the export function and test the output file.
3. Add the quick-run menu option.
4. Record the progress video showing one of the new features.
5. Update the weekly stand-up in the main README.

---

*This document is a living plan and will be updated as features are implemented.*

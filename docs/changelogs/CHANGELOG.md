# Virus Spread Lab Changelog

## 2026-11-09 – Instructor feedback fixes
- Fixed compilation error in `runInteractiveSimulation()`: moved seed selection and result export inside the replay loop so `profileChoice`, `days`, and `initial` are in scope.
- Changed numeric input validation to use `std::getline` + `std::stoi` with `try/catch` (`std::invalid_argument` and `std::out_of_range`).
- Added meaningful pointer usage: selected `VirusProfile` objects are accessed through pointers in interactive runs, quick run, and profile comparison.
- Verified the program structure still compiles cleanly after the changes.

## Milestone 2 (Week of Nov 2–8, 2026)
- Added optional seed selection for repeatable simulations.
- Added save-results-to-file feature (`outbreak_report.txt`).
- Added Quick Run menu option with sensible defaults.
- Improved menu prompts, color feedback, and input validation.
- Kept class structure (Person, VirusProfile, Simulation) organized.

## Milestone 1
- Initial Virus Spread Lab simulation with grid, daily steps, and profile comparison.
- Separated logic into Person, VirusProfile, and Simulation classes.
- Basic menu and input handling.

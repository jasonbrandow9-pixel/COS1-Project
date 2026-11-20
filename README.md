# COS1 Project & Portfolio

This repository documents the development of a C++ portfolio project using Visual Studio, Git, GitHub, and iterative delivery.

## Portfolio website

The portfolio source page is in [index.html](./index.html), with shared styling in [styles.css](./styles.css), an interactive browser preview in [demo.html](./demo.html), and a resume page in [resume.html](./resume.html). See [docs/PORTFOLIO.md](./docs/PORTFOLIO.md) for the assignment's GitHub Pages repository requirement and deployment notes.

## Current project: Virus Spread Lab

Virus Spread Lab is an educational console simulation that models how simplified contact frequency, transmission chance, and recovery time can affect an outbreak on a grid. It is an illustrative classroom model, not a medical forecast.

### Current features

- Grid-based outbreak simulation with daily susceptible, infected, recovered, and new-infection counts.
- Separate `Person`, `VirusProfile`, and `Simulation` classes.
- Three illustrative virus profiles for comparison.
- Interactive simulation settings and a Quick Run path with defaults.
- Optional repeatable seed selection.
- Optional export to `outbreak_report.txt`.
- Input validation with clear messages for invalid and out-of-range values.
- Help screen explaining the grid, recovery behavior, and model assumptions.
- Replay flow for running another simulation without restarting the program.

## Build and run

1. Open `dev/COS1-Project.sln` in Visual Studio.
2. Select the **Debug** configuration and **x64** platform.
3. Choose **Build > Build Solution**.
4. Run with **Debug > Start Without Debugging**.

Project-specific instructions are in [`dev/COS1-Console/README.md`](./dev/COS1-Console/README.md).

## Milestone 4 status

The final development pass addressed the replay-loop scope issue, improved line-based input validation with `std::getline` and `std::stoi`, preserved pointer-based access to the selected profile, and kept seed selection and optional report export inside the valid simulation scope. Additional details are documented in [`docs/Milestone4.md`](./docs/Milestone4.md).

## Weekly stand-up

### Week 1

Set up the repository and Visual Studio solution, built the first console feature, and established the project structure.

### Week 2

Added repeatable seeds, result export, Quick Run defaults, stronger input handling, and clearer menu navigation.

### Week 3

Fixed the compilation and scope problem in `runInteractiveSimulation`, improved numeric input handling, and used a pointer for the selected profile.

### Week 4 — Final stand-up

Completed the final development and documentation pass. Reviewed the application flow, validation behavior, replay loop, profile comparison, Quick Run path, Help screen, result export, and GitHub history. The main takeaway was that small commits, clear issues, readable class boundaries, and a final review make debugging and delivery more manageable.

## Future development

Possible next steps include custom settings for a single run, a quarantine-strength control, automated checks for infection and recovery rules, a richer comparison report, and further separation of input and reporting from the simulation model.

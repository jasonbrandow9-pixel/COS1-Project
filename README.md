# COS1 Project & Portfolio

This repository documents the development of a small C++ portfolio project while practicing Git, Visual Studio, documentation, and iterative delivery.

## Current project: Virus Spread Lab

The first project in `dev/COS1-Console` is **Virus Spread Lab**, an interactive educational simulation of transmission and recovery on a grid. It helps visualize how relative contact frequency, transmission chance, and recovery time can affect outbreak curves.

The program includes a live grid, daily statistics, a spread-factor metric, illustrative profile comparisons, and an explanation of the model assumptions. It uses only the C++ standard library and clearly separates classroom simulation from real-world medical data.

## Build the project

1. Open `dev/COS1-Project.sln` in Visual Studio.
2. Select the **Debug** configuration and **x64** platform.
3. Build with **Build > Build Solution**.
4. Run with **Debug > Start Without Debugging**.

See [`dev/COS1-Console/README.md`](./dev/COS1-Console/README.md) for the feature list and project-specific instructions.

## Weekly stand-up

### Week 1

- **Overview:** Set up the repository, created the Visual Studio solution, and built the first interactive C++ feature.
- **Challenges:** Started with a blank console project and needed to create a structure that would be easy to extend without adding unnecessary dependencies.
- **Accomplishments:** Added the first working console application and documented the build process.
- **Next steps:** Turned the project into a safe virus-spread simulation with an interactive grid, daily metrics, and profile comparisons.

### Week 2

- **Overview:** Expanded Virus Spread Lab with repeatable seeds, result export, and a Quick Run option. Improved input validation and menu clarity.
- **Challenges:** Making sure the same seed produced identical results and that the report file wrote correctly from Visual Studio. Addressed by testing the same seed twice and verifying the output file.
- **Accomplishments:** Added seed control, file saving, Quick Run defaults, and stronger error handling so the program is easier for others to use. Kept the existing class structure clean.
- **Next steps:** Implement remaining open Issues (custom virus settings, simple quarantine option, richer comparison table) and add light automated checks for the simulation rules.

### Week 3

- **Overview:** Fixed the compilation error in runInteractiveSimulation and improved input validation and pointer usage based on instructor feedback.
- **Improvements:** Moved seed and export logic inside the replay loop, switched numeric input to getline/stoi/try-catch, and added pointer usage for the selected profile.
- **Challenges:** Variables were out of scope after the replay loop. Resolved by moving the dependent code inside the loop.
- **Accomplishments:** Program now compiles cleanly and input handling matches the required style. Documentation and changelog are up to date.
- **Next steps:** Continue refactoring, implement custom virus settings, and finish remaining open Issues.

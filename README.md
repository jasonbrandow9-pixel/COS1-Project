# COS1 Project & Portfolio

This repository documents the development of a small C++ portfolio project while practicing Git, Visual Studio, documentation, and iterative delivery.

## Current project: Virus Spread Lab

The project in `dev/COS1-Console` is **Virus Spread Lab**, an interactive educational simulation of transmission and recovery on a grid. It helps visualize how contact frequency, transmission chance, and recovery time can affect outbreak curves.

The program includes a live grid, daily statistics, a spread-factor metric, illustrative profile comparisons, and an explanation of the model assumptions. It uses only the C++ standard library and clearly separates classroom simulation from real-world medical data.

## Build the project

1. Open `dev/COS1-Project.sln` in Visual Studio.
2. Select the **Debug** configuration and **x64** platform.
3. Build with **Build > Build Solution**.
4. Run with **Debug > Start Without Debugging**.

See [`dev/COS1-Console/README.md`](./dev/COS1-Console/README.md) for the feature list and project-specific instructions.

## Weekly Stand-Up

### Week 1
- **Overview:** Set up the repository, created the Visual Studio solution, and built the first interactive C++ feature set (Person, VirusProfile, Simulation).
- **Challenges:** Starting from a blank console project and deciding on a clean class structure that would be easy to extend.
- **Accomplishments:** Working menu, live grid, daily reports, and basic profile comparisons.
- **Next steps:** Expand features, improve usability, and document the changes for Milestone 2.

### Week 2
- **Overview:** Expanded the simulation with a richer final summary (peak day, ever-infected percentage, plain-English reading), added a replay option after each run, and improved input validation messages. Also completed the Milestone 2 planning worksheet and documentation.
- **Challenges:** Keeping the output clear and useful without turning the program into something that looks like real medical advice. Making sure every small change still compiled and stayed organized.
- **Accomplishments:** Usability improvements that a new user would notice, better end-of-run feedback, and multiple focused commits that show the project evolving.
- **Next steps:** Look at custom one-off virus settings, a simple quarantine toggle, and any feedback from the Week 2 stand-up and peer responses before deciding what to prioritize for Week 3.

---

**Student:** Jason Brandow  
**Instructor access:** kari-asphodel (repository + project board)

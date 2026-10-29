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

- **Overview:** Built the Virus Spread Lab simulation and added illustrative transmission profiles.
- **Challenges:** Needed to make the model understandable without presenting simplified values as medical facts.
- **Accomplishments:** Added susceptible/infected/recovered states, recovery timing, spread-factor reporting, comparison mode, and an assumptions screen.
- **Next steps:** Add repeatable scenario seeds, automated checks for the simulation rules, and exportable results.

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
# Project & Portfolio 1

### Jason Brandow

Hey, my name is Jason Brandow. I'm a student working on this for class. Main reason for this repo is to get better at using version control and start building some kind of portfolio with the stuff I do this term.

<br>

## 📢 &nbsp; Weekly Stand Up

Each week I will summarize my milestone activity and progress by writing a stand-up. A stand-up is meant to be a succinct update on how things are going. Use these prompts as a guide on what to write about:

⚙️ Overview - What I worked on this past week
<br>
🌵 Challenges - What problems did I have & how I'm addressing them
<br>
🏆 Accomplishments - What is something I "leveled up" on this week
<br>
🔮 Next Steps - What I plan to prioritize and do next

<br>

### Week 1

Got the repo created and cloned down to my computer this week. Spent a good bit of time looking through the docs so I know what the folders are for. Made a couple test commits just to make sure push was working.

Biggest issue was just getting used to the folder structure and not editing the wrong files. After the first couple tries it started making more sense.

Feel like I finally get the basic clone / commit / push loop now. Next up I'm gonna try putting some actual code in the dev folder and keep adding to this README every week.

### Week 2

- **Overview:** Expanded Virus Spread Lab with repeatable seeds, result export, and a Quick Run option. Improved input validation and menu clarity.
- **Challenges:** Making sure the same seed produced identical results and that the report file wrote correctly from Visual Studio. Addressed by testing the same seed twice and verifying the output file.
- **Accomplishments:** Added seed control, file saving, Quick Run defaults, and stronger error handling so the program is easier for others to use. Kept the existing class structure clean.
- **Next steps:** Implement remaining open Issues (custom virus settings, simple quarantine option, richer comparison table) and add light automated checks for the simulation rules.

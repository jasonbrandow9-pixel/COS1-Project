# Virus Spread Lab — Version Control and Project Documentation

## Project overview

Virus Spread Lab is a small C++ console program that shows how an outbreak can change over time on a grid. The model is intentionally simplified for classroom use. It is not a medical forecast and the profile values are illustrative rather than clinical measurements.

## What the program can do

- Run a daily outbreak simulation on a 30 by 14 grid.
- Show susceptible, infected, and recovered people with a live text grid.
- Report daily counts, new infections, and a spread-factor value.
- Compare three illustrative transmission profiles using the same population and starting conditions.
- Explain the model assumptions from the main menu.

## Repository layout

```text
COS1-Project/
├── dev/
│   ├── COS1-Project.sln
│   └── COS1-Console/
│       ├── COS1-Console.cpp
│       ├── Person.h / Person.cpp
│       ├── VirusProfile.h / VirusProfile.cpp
│       ├── Simulation.h / Simulation.cpp
│       └── README.md
├── docs/
│   ├── JBrandow-VersionControl.md
│   └── JBrandow-ProjectPlan.md
├── images/
└── tests/
    └── COS1-ConsoleSmoke.ps1
```

## Build and run

1. Open `dev/COS1-Project.sln` in Visual Studio.
2. Select **Debug** and **x64**.
3. Choose **Build > Build Solution**.
4. Run with **Debug > Start Without Debugging**.
5. Select an option from the main menu. The program validates numeric input and returns to the menu after each activity.

The smoke-test script can also run against a built executable:

```powershell
powershell -ExecutionPolicy Bypass -File .\tests\COS1-ConsoleSmoke.ps1 `
  -ExecutablePath .\x64\Debug\COS1-Console.exe
```

## Git workflow used for this project

I used small, meaningful commits instead of waiting until the end of the milestone. The commit history shows the project moving from the initial console application to separated classes, simulation behavior, menu validation, documentation, and testing evidence.

Typical workflow:

```bash
git status
git add docs/JBrandow-VersionControl.md
git commit -m "Add project version control documentation"
git push origin dev
```

Before submitting, I check that the working tree is clean, the intended branch is pushed, and the final branch contains the version being submitted.

## Markdown examples used here

- `#` and `##` headings organize the document.
- Bullet lists describe features and steps.
- Fenced code blocks show the repository tree, commands, and PowerShell examples.
- Backticks identify file names, commands, and class names.
- Relative links keep the documentation usable when viewed on GitHub.

## Current limitations and next steps

The model only checks nearby grid cells and uses random seeds for each interactive run. A future milestone could add repeatable scenario controls, result export, and automated unit tests for individual transmission and recovery rules.

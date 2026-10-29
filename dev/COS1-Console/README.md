# Virus Spread Lab

Virus Spread Lab is a safe, educational C++ console simulation that visualizes how transmission chance, contact frequency, and recovery time can change the shape of an outbreak. It is a classroom model, not medical advice or a clinical forecast.

## Features

- Grid visualization of susceptible, infected, and recovered people
- Daily outbreak report with susceptible, infected, recovered, and new-infection counts
- Spread-factor metric to show outbreak momentum over time
- Illustrative low-, moderate-, and high-transmission profiles
- Profile comparison using the same population size and starting conditions
- Explanation screen describing the model assumptions
- Validated menus and standard-library-only C++

The profiles use intentionally simplified relative settings. They should not be interpreted as real-world measurements for a named disease.

## Build and run

1. Open `../COS1-Project.sln` in Visual Studio.
2. Select **Debug** and **x64**.
3. Choose **Build > Build Solution**.
4. Run with **Debug > Start Without Debugging**.

Choose **Run an outbreak simulation** for a live grid, **Compare illustrative profiles** for a summary table, or **Learn how the model works** for the assumptions behind the simulation.

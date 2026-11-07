# Milestone 2 Documentation
**Student:** Jason Brandow  
**Project:** Virus Spread Lab  
**Course:** COS1 – Project & Portfolio 1  
**Date:** November 2026

---

## Overview

This document records the changes made during Milestone 2. The focus was on expanding the Virus Spread Lab simulation with new features from the planning worksheet, improving usability, and keeping the code organized.

---

## Features Added

### 1. Optional Seed Selection
Users can now choose to run a simulation with a specific seed number.  
- If they answer yes, they enter a seed.  
- If they answer no, a random seed is generated.  
This makes runs repeatable for testing and comparison.

### 2. Save Results to File
After a simulation finishes, the program asks if the user wants to save a summary.  
The file `outbreak_report.txt` includes:
- Profile name
- Seed used
- Days run
- Peak infected
- Final infected and recovered counts

### 3. Quick Run Option
A new menu choice (option 2) runs a simulation with sensible defaults:
- Seasonal-flu style profile
- 30 days
- 3 initial infected
- Random seed  
This reduces the number of questions for quick testing.

---

## Usability Improvements

- **Clearer prompts and feedback** – Color-coded banners, section headers, and error messages make the console easier to follow.
- **Stronger input validation** – `readMenuChoice()` and `readYesNo()` loops reject invalid input and ask again instead of crashing.
- **Improved menu structure** – Main menu now has five clear options including Quick Run and an explanation screen.
- **Helpful confirmation questions** – Users are asked before saving a file and before using a custom seed.

These changes make the program easier for someone else to use without needing to read the code.

---

## Code Structure Updates

- Kept the existing class design:
  - `Person` – tracks infection state and recovery timing
  - `VirusProfile` – holds contacts, transmission chance, and recovery days
  - `Simulation` – manages the grid, daily steps, and summary data
- Most new logic was added in `COS1-Console.cpp` as helper functions:
  - `readYesNo()`
  - `saveResults()`
  - `quickRun()`
  - Updated `runInteractiveSimulation()` to support seeds and file saving
- No major restructuring of the classes was required because `Simulation::reset` already accepted a seed.

---

## What Changed and Why

| Change | Reason |
|--------|--------|
| Added seed prompt | Allows repeatable tests and easier debugging |
| Added file export | Gives users a permanent record of a run |
| Added Quick Run | Reduces friction for common testing scenarios |
| Improved validation & prompts | Prevents crashes and makes the program clearer for new users |
| Kept class structure mostly unchanged | Existing design already supported the new features cleanly |

---

## Testing Notes

- Ran the same seed twice and confirmed matching results.
- Tested invalid menu input and yes/no answers – program recovers cleanly.
- Verified the report file is created with correct numbers.
- Quick Run produces a full simulation without extra questions.

---

## Summary

Milestone 2 added three planned features (seed control, result saving, and quick run) plus clear usability improvements around input handling and menu flow. The program is more useful for both demonstration and personal testing while remaining organized and easy to extend.

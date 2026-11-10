# Milestone 3 Documentation
**Student:** Jason Brandow  
**Project:** Virus Spread Lab  
**Course:** COS1 – Project & Portfolio 1  
**Date:** November 2026

---

## Overview

This document records the changes made during Milestone 3. The focus was on fixing issues identified by the instructor, improving code quality through refactoring, and continuing feature development.

---

## Features Added / Fixed

### Scope Fix and Seed/Export Integration
Moved the seed selection and result-export logic inside the replay loop in `runInteractiveSimulation()`.  
Previously, `profileChoice`, `days`, and `initial` were declared inside the loop but used outside it, which prevented the program from compiling. The features now work correctly and the program builds successfully.

### Pointer Usage
Added meaningful pointer usage by accessing the selected `VirusProfile` through a `const VirusProfile*` pointer in the interactive simulation, Quick Run, and profile comparison functions. This demonstrates deliberate pointer use while keeping the existing class design intact.

---

## Refactoring Improvements

### Numeric Input Validation
Replaced the previous `std::cin >>` approach in `readMenuChoice()` with the Day 3 lecture style:
- `std::getline` to read a full line
- `std::stoi` to convert to an integer
- `try/catch` blocks for `std::invalid_argument` and `std::out_of_range`

**Why:** This makes input handling more robust, matches the required course approach, and gives clearer error messages without leaving the input stream in a bad state.

### Code Organization
Kept the existing class structure (`Person`, `VirusProfile`, `Simulation`) and moved new logic into helper functions rather than expanding `main()`. This keeps responsibilities clearer and makes the main loop easier to follow.

**Why:** Improves readability and maintainability without changing the program’s behavior.

---

## What Changed and Why

| Change | Reason |
|--------|--------|
| Moved seed and save logic inside the replay loop | Fixed compilation error caused by variables being out of scope |
| Switched to getline + stoi + try/catch | Followed required input validation style and improved error handling |
| Added pointer usage for selected profiles | Met the requirement for meaningful pointer use and made profile selection clearer |
| Created real changelog | Replaced the placeholder so documentation accurately reflects project history |

---

## Commit History Highlights (Milestone 3)

- Fix scope bug in runInteractiveSimulation, switch numeric input to getline/stoi/try-catch, and add pointer usage
- Add actual project changelog

These commits address instructor feedback and improve code quality.

---

## Testing Notes

- Verified the program compiles successfully after the scope fix.
- Tested seed selection, result export, and replay loop to confirm features still work.
- Confirmed invalid numeric input is handled cleanly with the new validation approach.

---

## Summary

Milestone 3 focused on correcting the compilation error, aligning input validation with course standards, adding pointer usage, and documenting the changes. The project is more stable and better organized while retaining all previous features.

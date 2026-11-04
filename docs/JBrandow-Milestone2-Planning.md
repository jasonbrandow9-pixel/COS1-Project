# Milestone 2: Planning Worksheet
**Student:** Jason Brandow  
**Project:** Virus Spread Lab  
**Course:** COS1 – Project & Portfolio 1  
**Date:** November 4, 2026

---

## 1. Current Project Overview

Virus Spread Lab is the C++ console program I built. It shows how a virus can spread on a grid. Each spot is a person who can be susceptible, infected, or recovered. Right now I have three example profiles, a live grid that updates, daily numbers, a spread factor, a comparison mode, and a screen that explains the model.

What I already have working:
- 30 by 14 grid (420 people)
- Three profiles (common-cold style, seasonal-flu style, high-transmission style)
- Grid view and daily report
- Profile comparison
- Menu that checks input so it doesn’t crash
- Simulation::reset already takes a seed

Classes I made:
- Person – keeps track of if someone is sick and how long
- VirusProfile – holds the settings for contacts, chance, and recovery days
- Simulation – does the grid, the daily steps, and the reports
- Main file – menu and user prompts

---

## 2. Inspiration & Research

I looked at simple SIR models and other console simulations people have made for class. A lot of them use a grid with clear symbols, random contacts, and preset scenarios so you can compare without typing a bunch of numbers every time. Daily summary numbers also help so you don’t have to stare at the grid the whole time.

Things that seemed to work well for me:
- Different symbols for each state
- Preset profiles instead of making the user set everything
- A note that the numbers are just for the classroom and not real medical data

---

## 3. Planned Features

### Feature 1: Repeatable Seeds
I want the user to be able to type in a seed number so the same settings give the same outbreak every time. That will make it easier for me to test and to show the same run twice if I need to.

How I plan to do it:
1. User picks a profile
2. I ask if they want to use a specific seed
3. If yes, I read a number and use it
4. If no, I keep doing what it does now with random
5. I pass that seed into reset

### Feature 2: Save Results to a File
After a run finishes, I want to ask if they want to save a text file with the summary. The file would have the profile name, the seed, peak infected, and the final numbers.

### Feature 3: Easier to Use
- I want to add a quick run option that just uses some defaults so I don’t have to answer every question every time
- Maybe ask for confirmation if the run is going to be long
- Make the comparison table a little wider so the names fit better

### Feature 4: Simple Checks (if I have time)
I might add small tests to make sure the population count stays the same and that people recover on the right day. I could hide it behind a menu option I only use while testing.

---

## 4. How the Program Will Work

I’m thinking the main menu will look something like:
1. Run a simulation
2. Quick run
3. Compare profiles
4. How the model works
5. Exit

When they run a simulation:
- Pick profile, days, and starting infected (same as now)
- New question about using a seed
- Run it and show the grid and daily numbers
- At the end ask if they want to save a file
- Then go back to the menu

I’ll keep the input checking I already have so bad input doesn’t break it.

---

## 5. Code Changes

Most of the work will be in the main file (COS1-Console.cpp). I need to add the new prompts and a function that writes the text file. Simulation already takes a seed, so I probably don’t need to change the class much.

New helper functions I’ll add in main:
- One to read yes or no
- One to read a seed number
- One to write the results file

---

## 6. Things That Might Be Tricky

- Making sure the text file ends up in the right folder when I run it from Visual Studio
- Checking that the same seed really gives the same results
- Not letting the console get too long on big runs (I already only reprint the grid every 5 days, so that should be fine)

---

## 7. How I’ll Test It

1. Run the same seed twice and see if the numbers match
2. Save a file and open it to check the numbers
3. Try typing letters and bad numbers on the new prompts
4. Try the quick run and a normal run

---

## 8. What Done Looks Like for Me

- I can pick a seed and get the same outbreak again
- I can save a text file with the results
- Quick run works
- New prompts don’t crash on bad input
- This planning file is done and I can show at least one of the new features in the video

---

## 9. Next Steps

1. Add the seed prompt and test it
2. Add the save-to-file part
3. Add the quick run option
4. Record the video
5. Update the stand-up in the main README

---

This is the plan I’m going to follow this week. I’ll update it if I change anything while I’m coding.

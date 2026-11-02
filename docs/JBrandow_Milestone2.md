# Milestone 2 Notes
**Jason Brandow**  
**Virus Spread Lab – Week 2**

## What I worked on

This week I focused on making the simulation easier to use and giving better feedback at the end of a run.

The same three classes are still there (Person, VirusProfile, Simulation). I just extended them a bit and cleaned up the menu.

## Features I added

**Better final summary**  
After a run finishes it now shows:
- how many days actually ran
- the highest number of infected people and which day that happened
- how many people were ever infected (with a percent)
- a short note saying if the outbreak looked contained, moderate, or high spread

**Run again option**  
When a simulation ends you can choose to start another one right away instead of going all the way back to the main menu.

**Clearer menu errors**  
The prompts tell you the range you’re supposed to enter. If you type something wrong it says exactly what it wants instead of a generic message.

**Planning worksheet**  
Filled out the Milestone 2 planning doc and put it in the docs folder.

## Files that changed

- Simulation.h / Simulation.cpp – added peak day and ever-infected tracking, plus the new summary printout
- COS1-Console.cpp – better validation messages and the replay loop
- docs/JBrandow-Milestone2-Planning.md – planning worksheet
- docs/JBrandow_Milestone2.md – this file

## Usability

The main usability changes are the clearer error messages and the option to run again without leaving the simulation menu. Both make it less annoying when you’re testing different settings.

## Testing

I compiled everything with g++ while I was working on it. Also tried bad menu input (letters, numbers way outside the range) to make sure the new messages showed up correctly.

## What’s next

Still thinking about letting the user tweak the virus settings for a single run and maybe a simple quarantine option. I’ll decide after I get some feedback from the stand-up this week.

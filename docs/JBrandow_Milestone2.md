# Milestone 2 Documentation
Jason Brandow  
Virus Spread Lab – Week 2

## What I worked on

This week I focused on making the simulation easier to use and giving better feedback at the end of a run. I kept the same three classes (Person, VirusProfile, Simulation) and just added to them.

## Features that got added

**Better final summary**  
After a run finishes it now shows:
- how many days actually ran
- the highest number of infected people and which day that happened
- how many people were ever infected (and the percent of the whole grid)
- a short note saying whether the outbreak looked contained, moderate, or high spread

**Run again option**  
When a simulation ends you can choose to start another one right away instead of going all the way back to the main menu.

**Clearer menu errors**  
The prompts tell you the allowed numbers up front. If you type something wrong it says exactly what it wants instead of a vague “invalid” message.

**Planning worksheet**  
I filled out the planning doc and put it in the docs folder.

## Files that changed

- Simulation.h – added peakDay and everInfected to the summary
- Simulation.cpp – tracks the peak day and prints the new summary
- COS1-Console.cpp – better validation text and the replay loop
- docs/JBrandow-Milestone2-Planning.md – planning worksheet
- docs/JBrandow_Milestone2.md – this file

## Why these changes

The summary was pretty thin before. Knowing the peak day and how many people ever got hit makes it easier to compare the different profiles. The run-again option just saves time when I’m testing. The clearer error messages were the main usability thing for this week.

## Testing

I compiled everything with g++ while I was working on it. Tried bad input (letters, numbers way outside the range) to make sure the new messages showed up. Also ran a few short simulations to check that the peak day and percent numbers looked right.

## What’s next

Still thinking about letting the user tweak the virus settings for a single run, and maybe a simple quarantine option. I’ll decide after I get feedback from the stand-up this week.

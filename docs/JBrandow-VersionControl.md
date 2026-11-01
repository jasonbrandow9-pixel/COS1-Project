# Version Control & Markdown Documentation

**Course:** COS1 – Project & Portfolio 1  
**Student:** Jason Brandow  
**Date:** November 1, 2026

---

## Why Version Control Matters

Version control keeps a history of every change I make to the project.  
If something breaks, I can go back to a working version.  
It also lets me work in small steps instead of trying to finish everything in one big save.

For this class I use Git and GitHub.  
All real work happens on the `dev` branch.  
When a set of changes is ready, I open a pull request into `main`.

---

## Basic Git Commands I Use

| Command | What it does |
|---------|--------------|
| `git status` | Shows what files changed |
| `git add .` | Stages all current changes |
| `git commit -m "message"` | Saves a snapshot with a short note |
| `git push` | Uploads commits to GitHub |
| `git pull` | Downloads the latest changes |
| `git checkout -b branchname` | Creates and switches to a new branch |
| `git log --oneline` | Shows a short list of recent commits |

I try to commit after every meaningful change instead of waiting until the end of the day.

---

## Markdown Basics

Markdown is a simple way to format text so GitHub can display it cleanly.

Common things I use:

- `#` for main headings
- `##` and `###` for smaller headings
- `**bold**` and `*italic*`
- `-` or `*` for bullet lists
- `` `code` `` for inline code
- Triple backticks for code blocks
- Links: `[text](url)`

I write most documentation in Markdown so it stays readable both in the editor and on GitHub.

---

## How I Organize This Repository

- `dev/` – all C++ source code and Visual Studio project files
- `docs/` – course materials, changelogs, validation notes, and this document
- `images/` – screenshots of the project board, repo, and access settings
- Root `README.md` – project overview and weekly stand-ups

This layout makes it easier to find code versus notes.

---

## Commit Habit

I aim for small, clear commits that describe what actually changed.  
Examples of good messages:

- Add Person class with health states
- Wire up Simulation grid and daily report
- Fix input validation on menu choices
- Update README with Week 2 stand-up

Bad messages (I try to avoid):

- update
- stuff
- final version

---

## Resources I Used

- [GitHub Markdown Guide](https://guides.github.com/features/mastering-markdown/)
- Course Getting Started docs inside this repository
- Visual Studio Git tools and the command line

---

*This document will grow as the project continues.*

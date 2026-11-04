# Version Control & Markdown

## COS119-O Project & Portfolio I

- **Jason Brandow**
- **November 1, 2026**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

**1. Using Terminal, there are essential commands to know.**

- `clear`: Clear the Screen
- `pwd`: Print the "Working Directory"
- `ls`: List files and folders
- `ls -a`: List files and folders, including invisible files
- `ls -lh`: List all files and folders, in human readable form
- `cd`: Change directory
- `cd /`: Change directory, go to root directory
- `cd ~`: Change directory and go to user home directory
- `cd ..`: Change directory, go up one folder level
- `cd ../..`: Change directory, go up two folder levels
- `cd ~/Desktop`: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

When I typed `cd` and a space, then dragged a folder into Terminal, it automatically filled in the full path to that folder. After I pressed return, Terminal changed into that directory. It was a fast way to move into a folder without typing the whole path by hand.

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git.

**1. There are three types of version control.**

1. **Local Version Control** – keeps change history on a single computer. Simple, but only works on that machine.
2. **Centralized Version Control** – one central server holds the full history. Everyone checks files in and out from that server (example: older systems like SVN).
3. **Distributed Version Control** – every developer has a full copy of the repository history. Git is this type. You can work offline and later sync with a remote like GitHub.

**2. Using Terminal, there are also essential Git commands to know.**

- `git clone`: Clone a repository
- `git config --global user.name "Your Name"`: Set-up a global user name
- `git config --global user.email "you@example.com"`: Set-up a global email address (to match my GitHub account email)
- `git status`: Shows the current state of your directory and staging area
- `git add .` or `git add filename`: Add modified files to the next commit
- `git commit -m "message"`: Make a commit with a new message
- `git log` or `git log --oneline`: Show my commit history
- `git help` or `git --help`: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

1. Copy the HTTPS clone URL from the GitHub repository page.
2. In Terminal run: `git clone https://github.com/username/repo-name.git`
3. When Git asks for credentials, use my GitHub username and a personal access token (or password if still accepted).
4. After the first successful login, macOS Keychain can store the credentials so I don’t have to type them every time.
5. For day-to-day work I use `git pull` to download updates and `git push` to upload my commits.

**4. Using .gitignore and Why it's Important**

- What is the purpose of this file?  
  The `.gitignore` file tells Git which files and folders to skip so they are never added to the repository. This keeps the repo clean and avoids committing temporary or machine-specific files.

- What is the "**.DS_Store**" file and why would you want to ignore it?  
  `.DS_Store` is a hidden macOS file that stores folder view settings. It is created automatically by Finder and is different on every computer, so it should be ignored so it doesn’t clutter the repo or cause unnecessary merge conflicts.

- What other file or folder would you want to add to a .gitignore file and why?  
  I would ignore the Visual Studio build folders such as `x64/`, `Debug/`, and `Release/`, and also `*.user` files. Those are generated when the project is built and are specific to each machine, so they don’t belong in the shared repository.

# Reference Links

**Research Summary:** The class materials and the official Git documentation were the most helpful this week. The GitHub docs on cloning and authentication made the HTTPS setup clearer, and the simple Terminal command list helped me practice without getting lost.

**Terminal Commands**  
https://ss64.com/osx/  
https://github.com/0nn0/terminal-mac-cheatsheet

**Three Types of Version Control**  
https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control

**Git Commands**  
https://git-scm.com/docs  
https://education.github.com/git-cheat-sheet-education.pdf

**Connecting to GitHub using Terminal**  
https://docs.github.com/en/get-started/getting-started-with-git/about-remote-repositories  
https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token

**Using .gitignore and Why it's Important**  
https://git-scm.com/docs/gitignore  
https://github.com/github/gitignore

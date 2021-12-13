# Mini-Shell


This is my attempt to make a mini shell similar to the one present in the computer.

The builtin/internal commands in my shell are:

- echo: The string to be printed must be enclosed in double quotes. The flag which can be handled is -e. This flag     will treat \t and \n as tab ad newline respectively. Echo can be used without flags too.
- history: Using history without any flags will print out all the commands given in the current session. The commands are stored in a file called history.txt. If we use -clear flag, history gets cleared.
- help: Help displays the contents of the help.txt which has all the commands of the shell.
- cd: This can be used to navigate. If just cd is typed, it will go to home. If cd .. is typed it will go to the previous directory. If cd 'name' is typed, it will go to 'name' directoy (provided it exists).
- pwd: This prints out the current working directory.

The code for these internal commmands is in main.c itself.


The external commands are: 

- mkdir: Can be used to create directories.
- rm: Can be used to remove files.
- cat: Can be used to display contents of file. Here > redirection works.
- ls: Can be used to show contents of a directory.
- date: Can be used to show date and time.
- man: Can be used to access manual pages.
- which: Can be used to locate executable file. 
- cal: Can be used to see calender.
- clear: Can be used to clear the window.
- touch: Can be used to create empty files.
- rmdir: Can be used to remove directories.
- cp: Can be used to copy files.

For these external commands I have used execvp to redirect to the files corresponding to the command.

The external commands can handle upto three arguments. Unfortunately the external commands cannot handle flags, as the code was becoming complicated and I have stored commands, flags and arguments seperately, so everytime the number of arguments or flags changes, a new execvp needs to be created.


Apart from this, I have employed piping using strtok.



## How to run the program?

The command to be given in terminal:

gcc main.c

./a.out


Operating Systems - CourseWork 1 - a Simple Linux Shell
GROUP MEMBERS:-
Objectives:-
Creat a working command line shell.
Gain experience in C language to create simple projects
Learn and implement the usage of Makefiles

Description:-
This is a project in which we have worked as a group in order to Develop and implement a command line shell on a specified UNIX platform. The shell was created using c language allowing the group to obtain many resources online. The command line shell supports the following internal commands:-

"help": shows a help menu with all the commands that is suitable for the shell <br>
"dir <directory>":  Lists the contents of the directory <br>
"print <comment>": Displays comment on the command line followed by a newline (multiple spaces is reduced to a single space).<br>
"environ": shows the environment strings and the full path for the shell executable. <br>
"cls": Clears the screen <br>
"md <directory>": - Create the folder <directory>.
"rd <directory>": - Remove the folder <directory>
"cd <directory>": - Change the current default directory to <directory> it also also change the PWD environment variable. <br>
"quit": Quits the shell <br>
```bash

# How to bulid the project:-
To build the project you must have myshell.c, utility.c, utility.h and makefile within the same repository
then switch to the directory of that repository and run the command "make". this will compile the project
and generate the binary file "myshell". In order to run the program on UNIX based Operating System type "./myshell" within the terminal. 
now the shell should be running.To quit the program simply type "quit" within the program.
to clean unwanted files within the directory type "make clean" in the terminal.

# I/O redirection:-
I/O redirection allows you to redirect command input and output, or to combine several commands using pipes. 
this is called "command pipeline."
The bash shell has three regular streams for I/O redirection (in Linux-like systems).
stdin or 0 – Input from stdin is taken by the bash shell. The keyboard is used as an input by default.
stdout or 1 – The shell bash sends output to the stdout. The performance is displayed.
stderr or 2 – The bash shell sends Stderr an error message. The error message will be revealed on screen.
I/O redirection thus enables you to adjust a command's input source as well as where the output and error messages are sent to. And this is made
possible by the redirection operators '<' and '>.'

# program environment:-
The program environment is mounted on your computer that can impact either the creation or testing of your application.
for example the operating system installed on your machine and the compilers/interpreters you are using these can affect your program.
for this project we have used a vmware with linux operating system and used the compiler "gcc". 

# background program execution:-
In Unix, independently of the shell, a background process runs, leaving the terminal free for other work. use "&" at the end of a command to run
a process in the background. This can be done within the terminal.

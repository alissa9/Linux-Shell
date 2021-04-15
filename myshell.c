/**
 * Operating Systems - CourseWork 1 - a Simple Linux Shell
 * Tutor: Ahmed Eissa
 * GROUP MEMBERS
 *<Mohamad Hamza Ibrahim M00737296> 
 *<Sohail Gasis M0071660 >  
 *<Mohamad Ikbal Alissa M00714688> 
 * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "utility.h"

// defining contants 
#define LINES_SIZE 1024
#define MAX_lines 10

int main(int argc, char *argv[])
{
	// Input buffer and and commands
	char environ[2][LINES_SIZE] = {0};
	char pwd[LINES_SIZE] = {0};
	char myshell[LINES_SIZE] = {0};
	char buffer[LINES_SIZE] = {0};
	char command[LINES_SIZE] = {0};
	char lines[MAX_lines][LINES_SIZE] = {0};
	int lines_count = 0;

	// creating a file pointer object
	// parsing the given commands and opening the file
	FILE *batchFile = NULL;

	if (argc > 1)
	{
		batchFile = fopen(argv[1], "r");
		if (batchFile == NULL)
		{
			printf("Error opening batch file...\n");
			return EXIT_FAILURE;
		}
	}
	else
	{
		batchFile = stdin;
	}

	// text displays when shell starts

	printf("\n-------------------- SHELL STARTED --------------------\n");
	printf("\n Type 'help' to display the shell commands\n\n");
	current_Dir(pwd);
	current_Dir(myshell);
	strcpy(environ[0], "PWD: ");
	strcpy(environ[1], "MYSHELL: ");
	strcat(environ[0], pwd);
	strcat(environ[1], myshell);

	printf("%s> ", pwd); // this prints the current directory. it works cos of "get_currentDir(pwd)";
	while (fgets(buffer, LINES_SIZE, batchFile) != NULL)
	{     
		// processing the lines to get the command followed by it's arguments
		int index = 0; // this allows command to be executed
		while (buffer[index] != '\n')
		{
			index++;
		}
		buffer[index] = '\0';

		lines_count = process_Lines(buffer, lines);//"buffer" is the string and "lines" has the broken string. "lines_count" stores the int of the size of the array "lines"
		strcpy(command, lines[0]);// this gets the first broken down string and copies it to the array of "command". so if i write the command "cd h" it gets the "cd" and puts "h" in the "command"

		/*
			checking if command is equal to "cd"
			then will call change_dir() and pass it the arge at index 1
		*/
		if (strcmp(command, "cd") == 0) // strcmp compares 2 string ("command" "cd") by every character and returns a int. 
			  						   //If the first character of two strings is equal, the next character of two strings are compared. 
									  //This continues until the corresponding characters of two strings is null character.
		{

			change_dir(pwd, lines[1]); //here you want "lines[1]" to be the directory you get into and "pwd" is the location of that directory
			strcpy(environ[0], "PWD: ");
			strcat(environ[0], pwd); //this appends "pwd" and environ[0] 
		}

		// clears the content in the shell screen
		else if (strcmp(command, "cls") == 0)
		{
			clear_screen();
		}

		//  if command is "help" then show_commands() is called
		else if (strcmp(command, "help") == 0)
		{
			show_Commands();
		}

		// if command is "dir" then list_Directories is called
		// and all directories are displayed in the shell
		else if (strcmp(command, "dir") == 0)
		{
			list_Directories(lines[1]);// this checks if "lines[1]" is empty if it is it prints current directories if not it prints "lines[1]" directories
			printf("\n");
		}

		//if command is "rd" then remove_Direcotory is called and the given directory is removed
		else if (strcmp(command, "rd") == 0)
		{
			remove_Direcotory(lines[1]);
		}

		//if command is "md" then make_Directory is called and anew directory is created
		else if (strcmp(command, "md") == 0)
		{
			create_Directory(lines[1]);
		}

		// if command is "print" then text is displayed in the shell
		else if (strcmp(command, "print") == 0)
		{
			printf("%s> ", pwd);
			for (int i = 1; i < lines_count; i++)
			{
				printf("%s ", lines[i]);
			}
			printf("\n");
		}

		// display environment variables
		else if (strcmp(command, "environ") == 0)
		{
			display_environs(environ);
		}

		// if command is "quit" or "exit" then the shell is terminated
		else if (strcmp(lines[0], "quit") == 0 || strcmp(lines[0], "exit") == 0)
		{
			printf("shell has closed!\n");
			return EXIT_SUCCESS;
		}

		// an error message is displayed if command is unrecognised
		else
		{
			printf("%s> ", pwd);
			printf("Invalid command, use 'help' to display the manual\n");
		}

		memset(buffer, 0, sizeof buffer);
		memset(command, 0, sizeof command);
		for (int i = 0; i < MAX_lines; i++)
		{
			memset(lines[i], 0, sizeof lines[i]);
		}

		printf("%s> ", pwd);
	}
	return EXIT_SUCCESS;
}

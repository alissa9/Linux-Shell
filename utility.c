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



/**
 * processes a line of arguments where each line is seperated by white space
 * line at index 0 is the command and the rest are it's arguments
 * @param lines an array of characters 
 * @param str each line 
*/
extern int process_Lines(char* str, char lines[][LINES_SIZE]){ //String tokenization is a process where a string is broken into several parts. Each part is called a token. For example, if "I am going" is a string, the discrete parts—such as "I", "am", and "going"—are the tokens.
	const char delimiter[2] = " "; // breaks down the string where there is a " " eg "i am hamza" this breaks down to "i" "am" "hamza"
	int lines_count = 0;
	char* token = strtok(str, delimiter);// strtok gets a string ("str") and breaks it down by the "delimiter"
	while (token != NULL){ // walk through other lines
		strcpy(lines[lines_count], token); // this copies "token" to the arrays of "lines[lines_count]""
		lines_count++; // increase size of array cos we just added a string 
		token = strtok(NULL, delimiter); // resets "token"
	}
	return lines_count;
}

/**
 * returns the current active directory 
 * @param pwd path of current directory
*/
extern void current_Dir(char* pwd){
	getcwd(pwd, LINES_SIZE); //cwd gets current directory in the array and The BUFFER_LEN argument is the size of the character array 
//if getcwd() is succesful it return the pwd argument which is the path. Otherwise, getcwd() shall return null
}

/**
 * changes directory to a given path as long as it is a valid path
 * @param pwd path of current directory
 * @param path path of new directory to change to 
*/
extern void change_dir(char* pwd, char* path){
	int changed = chdir(path); // "path" is the Directory path which the user want to make the current working directory. its zero (0) on success. -1 is returned on an error and errno is set appropriately.
	if (strcmp(path,"") != 0){ // strcmp compares 2 string ("path" "") by every character and returns a int. If the first character of two strings is equal, the next character of two strings are compared. This continues until the corresponding characters of two strings is 0.
		if (changed == 0){
			current_Dir(pwd);
		}
		else {
			printf("%s> No such path exists!\n", pwd);
		}
	}
}

// clears the screen
extern void clear_screen(void){
	system("cls||clear");
}



// displays help menu
extern void show_Commands(void){
    printf("\nAll Shell Commands : \n\n");
    printf("help\t\t\t - Displays all shell commands \n");
    printf("dir <directory>\t\t - Displays all directories\n");
    printf("environ\t\t\t -Displays the path of the current directory\n");
    printf("print      \t\t - Prints out a string to the shell \n");
	printf("cd <path>\t\t - Changes the working directory to the specified path.\n");
	printf("rd <path>\t\t - removes a specified directory\n");
	printf("md <path>\t\t - creates a new directory in a specfied path\n");
    printf("cls\t\t\t - Clears the screen.\n");
    printf("quit\t\t\t - Quits the shell.\n\n\n");
    
}
/**
 * removes a given directory from the current path
 * @param path 
*/
extern void remove_Direcotory(char* path){

rmdir(path);
}

/**
 * creates a directory in a given path with the following file permissions
 * @param path 
*/
extern void create_Directory(char* path){

mkdir(path, S_IRUSR | S_IRGRP | S_IROTH | S_IXUSR | S_IXGRP | S_IXOTH);
}

/**
 * displays all directories in a specified path
 * @param path 
*/
extern void list_Directories(char* path){
	struct dirent *de; 
	DIR *dr = NULL;
    if (strcmp(path, "") == 0){
        dr = opendir("."); // opens current directory
	}
    else {	
		dr = opendir(path); // opens directory in which u entered
	}
	if (dr == NULL) { 
		printf("Could not find the directory specified!\n" ); 
		exit(1);
	} 
	while ((de = readdir(dr)) != NULL){ // readdir reads through directories and prints it.
		printf("%s\n", de->d_name); 
	}
    closedir(dr);     
}

/**
 * displays the the path of the current directory
 * @param env
*/
extern void display_environs(char env[][LINES_SIZE]){
	printf("%s\n%s\n", env[0], env[1]);
}

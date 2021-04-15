/**
 * Operating Systems - CourseWork 1 - a Simple Linux Shell
 * Tutor: Ahmed Eissa
 * GROUP MEMBERS
 *<Mohamad Hamza Ibrahim M00737296> 
 *<Sohail Gasis M0071660 >  
 *<Mohamad Ikbal Alissa M00714688> 
 * 
*/
#ifndef UTILITY_H_
#define UTILITY_H_

#define LINES_SIZE 1024

// declaring all functions used in myshell.c and utility.c
 extern void show_Commands(void);

/**
 * processes a line of arguments where each line is seperated by white space
 * line at index 0 is the command and the rest are it's arguments
 * @param lines an array of characters 
 * @param str each line 
*/
extern int process_Lines(char* str, char lines[][LINES_SIZE]);

/**
 * returns the current active directory 
 * @param pwd path of current directory
*/
extern void current_Dir(char* pwd);

/**
 * changes directory to a given path as long as it is a valid path
 * @param pwd path of current directory
 * @param path path of new directory to change to 
*/
extern void change_dir(char* pwd, char* path);

// clears the screen
extern void clear_screen(void);

/**
 * removes a given directory from the current path
 * @param path 
*/
extern void remove_Direcotory(char* path);

/**
 * creates a directory in a given path with the following file permissions
 * @param path 
*/
extern void create_Directory(char* path);

/**
 * displays all directories in a specified path
 * @param path 
*/
extern void list_Directories(char* path);

/**
 * displays the the path of the current directory
 * @param env
*/
extern void display_environs(char env[][LINES_SIZE]);

#endif /* UTILITY_H_ */

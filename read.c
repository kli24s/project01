#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

#include "read.h"

//==================================================================
/*
Takes in a string, counts the number of spaces it has, returns that number
*/

int spaceCounter(char * str) {

  int numSpaces = 0;

  int i = 0;
  while (str[i]) {
    if (str[i] == ' ') numSpaces++;
    i++;
  }

  return numSpaces;

}

//==================================================================
/*
Takes in a string, counts number of delim it has, returns that number
*/

int counter(char * str, char delim) {
	//if the string is empty
	if (str[0] == '\0') {
		return 0;
	}

  int num = 0;

  int i = 0;
  while (str[i]) {
    if (str[i] == delim) num++;
    i++;
  }
  num++;

  return num;

}

//==================================================================
/*
Takes in a string (supposedly a single command the user entered) and returns an array of strings to include the whole SINGLE command and its arguments (ex. ls -a)
*/

char ** parse_command(char * line) {
  int spaces = spaceCounter(line);
  //instructions say string has no more than spaces arguments
  char ** ret = calloc(spaces, sizeof(char *));

   //loops through line to set ret[i] to a pointer
   //to the first word before a space and etc.
   int i;
   for(i = 0; line; i++) {
      ret[i] = strsep(&line, " ");
   }

   return ret;
}

//==================================================================
void execute(char * input, int * exitstatus) {
	char ** args = parse_command(input);
	//breaks while loop in main when exit
	if (strcmp(args[0], "exit") == 0) {
		*exitstatus = 0;
		return;
	}

	//normal executing without anything else
	execvp(args[0], args);
}

//==================================================================
void separate(char * input, int * exitstatus) {

}
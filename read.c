#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <sys/wait.h>

#include "redirection.h"
#include "pipes.h"

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
  //printf("spaces: %d\n", spaces);
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
/*
Takes in input (one command) and executes it, also signals to while loop in main to exit or not
*/
void execute(char * input, int * exitstatus) {
   int numInputs = spaceCounter(input);
	char ** args = parse_command(input);
   //rintf("numInputs: %d\n", numInputs);

	//breaks while loop in main when exit
	if (strcmp(args[0], "exit") == 0) {
		*exitstatus = 0;
		return;
	}

   if (strcmp(args[0], "cd") == 0) {
      chdir(args[1]);
      return;
   }

   int pid = fork();

   //parent process
   if (pid) {
      //stops parent from running until any child has exited
      int status;
      wait(&status);

      remove("tempfile.txt");

      free(args);
      return;
   } //child process
   else {
      int specialcase = 0;
      int i;
      for(i = 0; args[i]; i++) {
         if (strchr(args[i], '>')) {
            redirect_stdout_to(args, numInputs);
            specialcase = 1;
         }
         if (strchr(args[i], '<')) {
            redirect_stdin_from(args, numInputs);
            specialcase = 1;
         }
         if (strchr(args[i], '|')) {
            piping(args, numInputs);
            specialcase = 1;
         }
      }

      //normal executing
      if (specialcase == 0) execvp(args[0], args);
   }
}

//==================================================================
/*
Takes in input (if it has semicolons) and calls execute on each separate command
THERE MUST BE NO SPACE BEFORE AND AFTER SEMICOLONS
ex. works: " ls;ls -a"
    doesn't work: "ls; ls" or "ls ; ls"
*/
void separate(char * input, int * exitstatus) {
   int count = counter(input, ';');
   char ** commands = calloc(count, sizeof(char *));

   int i;
   for(i = 0; input; i++) {
      commands[i] = strsep(&input, ";");
   }

   for(i = 0; i < count; i++) {
      if (*exitstatus == 0) return;
      execute(commands[i], exitstatus);
   }

   free(commands);
}

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

/*
Performs piping on two commands in args using popen
@parameter args is the parsed arguments (a command) from the user input
@parameter numInputs is the number of inputs - 1 since it's based on spaces counted
*/
void piping(char ** args, int numInputs) {
   FILE *in;
   FILE * out;
   //first command, mode is r since we're reading from its output
   in = popen(args[0], "r");
   //second command, mode is w since we're writing to its input
   out = popen(args[numInputs], "w");

   char buff[1000];
   //puts in stream into buff
   while(fgets(buff, 1000, in)) {
      //writes string buff to the out stream
      fputs(buff, out);
   }

   pclose(in);
   pclose(out);
}

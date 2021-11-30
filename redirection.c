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

#include "read.h"

void redirect_stdout_to(char ** args, int numInputs) {
   int file = open(args[numInputs], O_CREAT | O_WRONLY | O_TRUNC, 0640);
   args[numInputs-1] = NULL;
   dup2(file, STDOUT_FILENO);
   execvp(args[0], args);
}

void redirect_stdin_from(char ** args, int numInputs) {
   int file = open(args[numInputs], O_RDONLY);
   args[numInputs-1] = NULL;
   dup2(file, STDIN_FILENO);
   execvp(args[0], args);
}

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

int main() {
	int exit = 1;
	//make it so execute changes *exit to 0 or false when a command is exit

	while (exit) {
		//command prompt with path
		char path[1000];
		printf("%s $: ", getcwd(path, 1000));

		//gets input and closes it off
		char input[1000];
		fgets(input, sizeof(input)-1, stdin);
		input[strlen(input)-1] = '\0';

		int numInputs = counter(input, ';');
		//printf("numInputs: %d\n", numInputs);

		if(numInputs <= 1) {
			if (numInputs == 1) execute(input, &exit);
		} else {
			separate(input, &exit);
		}

	}
	return 0;
}

/*
Performs redirection from stdout to a file
@parameter args is the parsed arguments (a command) from the user input
@parameter numInputs is the number of inputs - 1 since it's based on spaces counted
*/
void redirect_stdout_to(char ** args, int numInputs);

/*
Performs redirection stdin from a file
@parameter args is the parsed arguments (a command) from the user input
@parameter numInputs is the number of inputs - 1 since it's based on spaces counted
*/
void redirect_stdin_from(char ** args, int numInputs);

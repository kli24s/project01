# project01
Period 4, Chen Grace, Li Kyle
# Features Implemented #
- the parsing of a line including the fork and exec 
- exit and cd (although we didn't implement cd for ~) using chdir().
- reading and separating multiple commands with ; (SEE NOTES BELOW)
- simple redirection (SEE NOTES BELOW)

# Unsuccessful Features #
- wasn't able to implement redirection using multiple > or < in a command

# Bugs and more #
- multiple commands with ; should be used WITHOUT any spaces to the left or right of ;
- redirection only works using only one symbol (< or >) in the command
- piping limited to a single pipe

# Copy of Function Headers #
## main.c ##
**int main();**
- main function that starts the shell, takes in input from user, and calls appropriate functions
- @return default 0

## read.c ##
**int spaceCounter(char * str);**
- Takes in a string, counts the number of spaces it has, returns that number
- @parameter str is the string you want to count the number of spaces in
- @return int number of spaces in str

**int counter(char * str, char delim);**
- Takes in a string, counts number of delim it has, returns that number
- @parameter str is the string you want to count the number of delim in
- @parameter delim is the character you want to count in str
- @return int number of delim in str

**char ** parse_command(char * line);**
- Takes in a string (supposedly a single command the user entered) and returns an array of strings to include the whole SINGLE command and its arguments (ex. ls -a)
- @parameter line is the single command to be parsed into an array of arguments
- @return char ** array of all the arguments contained in line

**void execute(char * input, int * exitstatus);**
- Takes in input (one command) and executes it, also signals to while loop in main to exit or not
- @parameter input is the text the user enters into the shell
- @parameter exitstatus is used to exit the shell when appropriate

**void separate(char * input, int * exitstatus);**
- Takes in input (if it has semicolons) and calls execute on each separate command
- THERE MUST BE NO SPACE BEFORE AND AFTER SEMICOLONS
- ex. works: " ls;ls -a"
    - doesn't work: "ls; ls" or "ls ; ls"
- @parameter input is the text the user enters into the shell with semicolons
- @parameter exitstatus is used to exit when appropriate

## redirection.c ##
**void redirect_stdout_to(char ** args, int numInputs);**
- Performs redirection from stdout to a file
- @parameter args is the parsed arguments (a command) from the user input
- @parameter numInputs is the number of inputs - 1 since it's based on spaces counted

**void redirect_stdin_from(char ** args, int numInputs);**
- Performs redirection stdin from a file
- @parameter args is the parsed arguments (a command) from the user input
- @parameter numInputs is the number of inputs - 1 since it's based on spaces counted

## pipes.c ##
**void piping(char ** args, int numInputs);**

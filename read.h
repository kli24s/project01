/*
Takes in a string, counts the number of spaces it has, returns that number
@parameter str is the string you want to count the number of spaces in
@return int number of spaces in str
*/
int spaceCounter(char * str);

/*
Takes in a string, counts number of delim it has, returns that number
@parameter str is the string you want to count the number of delim in
@parameter delim is the character you want to count in str
@return int number of delim in str
*/
int counter(char * str, char delim);

/*
Takes in a string (supposedly a single command the user entered) and returns an array of strings to include the whole SINGLE command and its arguments (ex. ls -a)
@parameter line is the single command to be parsed into an array of arguments
@return char ** array of all the arguments contained in line
*/
char ** parse_command(char * line);

/*
Takes in input (one command) and executes it, also signals to while loop in main to exit or not
@parameter input is the text the user enters into the shell
@parameter exitstatus is used to exit the shell when appropriate
*/
void execute(char * input, int * exitstatus);

/*
Takes in input (if it has semicolons) and calls execute on each separate command
THERE MUST BE NO SPACE BEFORE AND AFTER SEMICOLONS
ex. works: " ls;ls -a"
    doesn't work: "ls; ls" or "ls ; ls"
@parameter input is the text the user enters into the shell with semicolons
@parameter exitstatus is used to exit when appropriate
*/
void separate(char * input, int * exitstatus);

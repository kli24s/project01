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

## read.c ##
**int spaceCounter(char * str);**

**int counter(char * str, char delim);**

**char ** parse_command(char * line);**

**void execute(char * input, int * exitstatus);**

**void separate(char * input, int * exitstatus);**

## redirection.c ##
**void redirect_stdout_to(char ** args, int numInputs);**

**void redirect_stdin_from(char ** args, int numInputs);**

## pipes.c ##
**void piping(char ** args, int numInputs);**



#include <stdio.h> 		//for all I-O ops (including stderr, perror)
#include <unistd.h>		//chdir(), fork(), exec(), pid_t
#include <sys/wait.h>	//waitpid() and other associated macros
#include <stdlib.h> 	//malloc(+ related) free() exit() execvp(check coz exec in unistd.h) EXIT_SUCCESS, EXIT_FAILURE
#include <string.h> 	//strcmp, strtok
#include <sys/types.h> 	//for pid_t and fork()
#include <ctype.h>		//for tolower()
#include <stdbool.h>	//to use bool variable
#include <limits.h>		//for PATH_MAX etc.

#define sz 100

int num_cmds = 0;

char** extract_cmds(char *input)
{
	num_cmds = 0;

	// If input is nothing we are returning NULL.

	if (strcmp(input,"") == 0)
		return NULL;

	int ptr = 0;

	// This while loop is to ignore the leading spaces before the input (if any).

	while(input[ptr] != '\0' && input[ptr] == ' '){
		ptr++;
    }

	char **commands = (char**)malloc(sz * sizeof(char*));

	// PIPING

    // I am assuming the delimiter as |. All commands seperated by | will be stored. There should not be any spaces on either side of the '|' character.

	char *token = strtok(input, "|");

	while (token != NULL){
		commands[num_cmds] = token;
		num_cmds++;
		token = strtok(NULL, "|");
	}

	return commands;
}

// This function handles all the external commands by creating child processes.

void ext_cmds(char *cmd, char *flag, char* args1[], char *args, int args1_len, int flag_len)
{
	int process;

    if (args1_len ==1 ){

        if (flag_len == 0){

            char* a_mkdir[]={"mkdir",args,NULL};
            char* a_rm[]={"rm",args,NULL};
            char* a_cat[]={"cat",args,NULL};
            char* a_ls[]={"ls",NULL};
            char* a_date[]={"date",NULL};
            char* a_man[]={"man",args,NULL};
            char* a_which[]={"which",args,NULL};
            char* a_cal[]={"ncal",NULL};
            char* a_clear[]={"clear",NULL};
            char* a_touch[]={"touch",args,NULL};
            char* a_rmdir[]={"rmdir",args,NULL};
            char* a_cp[]={"cp",args,NULL};

            // Process stores the value returned by fork(). If it is zero:

            if ((process = fork()) == 0){

                // MKDIR COMMAND

                if (strcmp(cmd, "mkdir") == 0){
                    execvp("mkdir", a_mkdir);
                }

                // RMDIR COMMAND

                else if (strcmp(cmd, "rmdir") == 0){
                    execvp("rmdir", a_rmdir);
                }

                // RM COMMAND

                else if (strcmp(cmd, "rm") == 0){
                    execvp("rm", a_rm);
                }

                // CAT COMMAND

                else if (strcmp(cmd, "cat") == 0){
                    execvp("cat", a_cat);
                }

                // LS COMMAND

                else if (strcmp(cmd, "ls") == 0){
                    execvp("ls", a_ls);
                }

                // DATE COMMAND

                else if (strcmp(cmd, "date") == 0){
                    execvp("date",a_date);
                }

                // MAN COMMAND

                else if (strcmp(cmd, "man") == 0){
                    execvp("man",a_man);
                }

                // WHICH COMMAND

                else if (strcmp(cmd, "which") == 0){
                    execvp("which",a_which);
                }

                // CAL COMMAND

                else if (strcmp(cmd, "cal") == 0){
                    execvp("ncal",a_cal);
                }

                // CLEAR COMMAND

                else if ((strcmp(cmd, "clear")) == 0){
                    execvp("clear",a_clear);
                }

                // TOUCH COMMAND

                else if ((strcmp(cmd, "touch")) == 0){
                    execvp("touch",a_touch);
                }

                // CP COMMAND     missing second file into which needs to be copied

                else if ((strcmp(cmd, "cp")) == 0){
                    execvp("cp",a_cp);
                }

                // If no command is given

                else if (strlen(cmd) == 0){
                    return;
                }

                else {
                    printf("Invalid command!\nType 'help' to see the list of valid commands\n");
                }
                exit(0);
            }

            //  If creation of child process was unsuccessful:

            else if (process < 0){
                // Error forking.
                perror("Error");
            }

            // Waiting for process to end.

            else{
                int x;
                waitpid(process, &x, 0);
            }
        }
    }

    else if (args1_len == 0){

        if (flag_len == 0){

            char* b_mkdir[]={"mkdir",NULL};
            char* b_rm[]={"rm",NULL};
            char* b_cat[]={"cat",NULL};
            char* b_ls[]={"ls",NULL};
            char* b_date[]={"date",NULL};
            char* b_man[]={"man",NULL};
            char* b_which[]={"which",NULL};
            char* b_cal[]={"ncal",NULL};
            char* b_clear[]={"clear",NULL};
            char* b_touch[]={"touch",NULL};
            char* b_rmdir[]={"rmdir",NULL};
            char* b_cp[]={"cp",NULL};

            // Process stores the value returned by fork(). If it is zero:

            if ((process = fork()) == 0){

                // MKDIR COMMAND

                if (strcmp(cmd, "mkdir") == 0){
                    execvp("mkdir", b_mkdir);
                }

                // RMDIR COMMAND

                else if (strcmp(cmd, "rmdir") == 0){
                    execvp("rmdir", b_rmdir);
                }

                // RM COMMAND

                else if (strcmp(cmd, "rm") == 0){
                    execvp("rm", b_rm);
                }

                // CAT COMMAND

                else if (strcmp(cmd, "cat") == 0){
                    execvp("cat", b_cat);
                }

                // LS COMMAND

                else if (strcmp(cmd, "ls") == 0){
                    execvp("ls", b_ls);
                }

                // DATE COMMAND

                else if (strcmp(cmd, "date") == 0){
                    execvp("date",b_date);
                }

                // MAN COMMAND

                else if (strcmp(cmd, "man") == 0){
                    execvp("man",b_man);
                }

                // WHICH COMMAND

                else if (strcmp(cmd, "which") == 0){
                    execvp("which",b_which);
                }

                // CAL COMMAND

                else if (strcmp(cmd, "cal") == 0){
                    execvp("ncal",b_cal);
                }

                // CLEAR COMMAND

                else if ((strcmp(cmd, "clear")) == 0){
                    execvp("clear",b_clear);
                }

                // TOUCH COMMAND

                else if ((strcmp(cmd, "touch")) == 0){
                    execvp("touch",b_touch);
                }

                // CP COMMAND     missing second file into which needs to be copied

                else if ((strcmp(cmd, "cp")) == 0){
                    execvp("cp",b_cp);
                }

                // If no command is given

                else if (strlen(cmd) == 0){
                    return;
                }

                else {
                    printf("Invalid command!\nType 'help' to see the list of valid commands\n");
                }
                exit(0);
            }

            //  If creation of child process was unsuccessful:

            else if (process < 0){
                // Error forking.
                perror("Error");
            }

            // Waiting for process to end.

            else{
                int x;
                waitpid(process, &x, 0);
            }
        }
    }


    else if (args1_len == 2){

        if (flag_len == 0){

            char* c_mkdir[]={"mkdir",args1[0],args1[1],NULL};
            char* c_rm[]={"rm",args1[0],args1[1],NULL};
            char* c_cat[]={"cat",args1[0],args1[1],NULL};
            char* c_ls[]={"ls",args1[0],args1[1],NULL};
            char* c_date[]={"date",args1[0],args1[1],NULL};
            char* c_man[]={"man",args1[0],args1[1],NULL};
            char* c_which[]={"which",args1[0],args1[1],NULL};
            char* c_cal[]={"ncal",args1[0],args1[1],NULL};
            char* c_clear[]={"clear",args1[0],args1[1],NULL};
            char* c_touch[]={"touch",args1[0],args1[1],args,NULL};
            char* c_rmdir[]={"rmdir",args1[0],args1[1],args,NULL};
            char* c_cp[]={"cp",args1[0],args1[1],NULL};

            // Process stores the value returned by fork(). If it is zero:

            if ((process = fork()) == 0){

                // MKDIR COMMAND

                if (strcmp(cmd, "mkdir") == 0){
                    execvp("mkdir", c_mkdir);
                }

                // RMDIR COMMAND

                else if (strcmp(cmd, "rmdir") == 0){
                    execvp("rmdir", c_rmdir);
                }

                // RM COMMAND

                else if (strcmp(cmd, "rm") == 0){
                    execvp("rm", c_rm);
                }

                // CAT COMMAND

                else if (strcmp(cmd, "cat") == 0){
                    execvp("cat", c_cat);
                }

                // LS COMMAND

                else if (strcmp(cmd, "ls") == 0){
                    execvp("ls", c_ls);
                }

                // DATE COMMAND

                else if (strcmp(cmd, "date") == 0){
                    execvp("date",c_date);
                }

                // MAN COMMAND

                else if (strcmp(cmd, "man") == 0){
                    execvp("man",c_man);
                }

                // WHICH COMMAND

                else if (strcmp(cmd, "which") == 0){
                    execvp("which",c_which);
                }

                // CAL COMMAND

                else if (strcmp(cmd, "cal") == 0){
                    execvp("ncal",c_cal);
                }

                // CLEAR COMMAND

                else if ((strcmp(cmd, "clear")) == 0){
                    execvp("clear",c_clear);
                }

                // TOUCH COMMAND

                else if ((strcmp(cmd, "touch")) == 0){
                    execvp("touch",c_touch);
                }

                // CP COMMAND     missing second file into which needs to be copied

                else if ((strcmp(cmd, "cp")) == 0){
                    execvp("cp",c_cp);
                }

                // If no command is given

                else if (strlen(cmd) == 0){
                    return;
                }

                else {
                    printf("Invalid command!\nType 'help' to see the list of valid commands\n");
                }
                exit(0);
            }

            //  If creation of child process was unsuccessful:

            else if (process < 0){
                // Error forking.
                perror("Error");
            }

            // Waiting for process to end.

            else{
                int x;
                waitpid(process, &x, 0);
            }
        }
    }

    else if (args1_len == 3 ){

        char* a_mkdir[]={"mkdir",args1[0],args1[1],args1[2],NULL};
        char* a_rm[]={"rm",args1[0],args1[1],args1[2],NULL};
        char* a_cat[]={"cat",args1[0],args1[2],NULL};
        char* a_ls[]={"ls",args1[0],args1[1],args1[2],NULL};
        char* a_date[]={"date",args1[0],args1[1],args1[2],NULL};
        char* a_man[]={"man",args1[0],args1[1],args1[2],NULL};
        char* a_which[]={"which",args1[0],args1[1],args1[2],NULL};
        char* a_cal[]={"ncal",args1[0],args1[1],args1[2],NULL};
        char* a_clear[]={"clear",args1[0],args1[1],args1[2],NULL};
        char* a_touch[]={"touch",args1[0],args1[1],args1[2],NULL};
        char* a_rmdir[]={"rmdir",args1[0],args1[1],args1[2],NULL};
        char* a_cp[]={"cp",args1[0],args1[1],args1[2],NULL};

        // Process stores the value returned by fork(). If it is zero:

        if ((process = fork()) == 0){

            // MKDIR COMMAND

            if (strcmp(cmd, "mkdir") == 0){
                execvp("mkdir", a_mkdir);
            }

            // RMDIR COMMAND

            else if (strcmp(cmd, "rmdir") == 0){
                execvp("rmdir", a_rmdir);
            }

            // RM COMMAND

            else if (strcmp(cmd, "rm") == 0){
                execvp("rm", a_rm);
            }

            // CAT COMMAND

            else if (strcmp(cmd, "cat") == 0){
                execvp("cat", a_cat);
            }

            // LS COMMAND

            else if (strcmp(cmd, "ls") == 0){
                execvp("ls", a_ls);
            }

            // DATE COMMAND

            else if (strcmp(cmd, "date") == 0){
                execvp("date",a_date);
            }

            // MAN COMMAND

            else if (strcmp(cmd, "man") == 0){
                execvp("man",a_man);
            }

            // WHICH COMMAND

            else if (strcmp(cmd, "which") == 0){
                execvp("which",a_which);
            }

            // CAL COMMAND

            else if (strcmp(cmd, "cal") == 0){
                execvp("ncal",a_cal);
            }

            // CLEAR COMMAND

            else if ((strcmp(cmd, "clear")) == 0){
                execvp("clear",a_clear);
            }

            // TOUCH COMMAND

            else if ((strcmp(cmd, "touch")) == 0){
                execvp("touch",a_touch);
            }

            // CP COMMAND     missing second file into which needs to be copied

            else if ((strcmp(cmd, "cp")) == 0){
                execvp("cp",a_cp);
            }

            // If no command is given

            else if (strlen(cmd) == 0){
                return;
            }

            else {
                printf("Invalid command!\nType 'help' to see the list of valid commands\n");
            }
            exit(0);
        }

        //  If creation of child process was unsuccessful:

        else if (process < 0){
            // Error forking.
            perror("Error");
        }

        // Waiting for process to end.

        else{
            int x;
            waitpid(process, &x, 0);
        }
    }

}


// Execute function which has all the builtins.

int execute(char *cmd, char *flag, char *args1[], char *args, int args1_len, int flag_len)
{

    // EXIT COMMAND

	if (strcmp(cmd, "exit") == 0){

        // If the command is 'exit' followed by any other words, its an invalid command.

		if (strlen(flag) || strlen(args)){
			printf("Error: Invalid command entered!");
			return 1;
		}
		return 0;
	}

    // CD COMMAND

	else if (strcmp(cmd, "cd") == 0){

        // If cd is followed by any flags, it is an invalid command.

		if (strlen(flag) != 0){
			printf("Error: No flags for this command!\n\n");
			return 1;
		}

		// If cd is not followed by any arguments, change directory to HOME.

		if (strlen(args) == 0)
			chdir(getenv("HOME"));

        // Otherwise, change directory to the pathname specified, which is stored in args.

		else{
			int res = chdir(args);
			if (res == -1)
				perror("Error");
		}
	}

    // ECHO COMMAND

    // The echo command can be given without any flags, in which case it will simply print the input text. It can also have flags -e or -n. The string to be echoed should be enclosed in double quotes.

	else if (strcmp(cmd, "echo") == 0){

        // Adding if condition to ensure that the string to be printed is enclosed in quotes.

		if (args[0] != '"'){
			printf("Error: Enclose string in quotes!\n\n");
			return 1;
		}

		if (args[strlen(args) - 1] != '"'){
			printf("Error: Expected end quotes!\n\n");
			return 1;
		}

		int len = 0;
		for(int i = 0; args[i] != '\0'; i++){
			len++;
		}

		len--;

		// While loop to remove trailing spaces in the string.

		while(len >= 0 && args[len] == ' '){
			args[len] = '\0';
			len--;
		}

		// If echo is not followed by any flag.

		if(strlen(flag) == 0){
			for(int i = 0; args[i] != '\0'; i++){
				if((i == 0 && args[i] == '"') || (args[i + 1] == '\0' && args[i] == '"'))
					continue;
				printf("%c", args[i]);
			}

			printf("\n");
		}

		// If flag is -n. This means that the next prompt will come on the same line in which the text is echoed.

		else if (strlen(flag) == 1){
			if (flag[0] == 'n'){
				for(int i = 0; args[i] != '\0'; i++){
					if((i == 0 && args[i] == '"') || (args[i + 1] == '\0' && args[i] == '"'))
						continue;
					printf("%c", args[i]);
				}
			}

			// If the flag is -e. This means that if "\t" or "\n" is encountered anywhere in the text to be echoed, it will treat it as a tab or newline and the remaining text will be printed after tab or newline.

			else if (flag[0] == 'e'){
				char *line = (char*)malloc(sz * sizeof(char));
				int ptr = 0;

				for(int i = 0; args[i] != '\0'; i++){
					if((i == 0 && args[i] == '"') || (args[i + 1] == '\0' && args[i] == '"'))
						continue;
					if(args[i] == '\\' && args[i + 1] == 'n'){
						line[ptr] = '\n';
						i++;
					}
					else if (args[i] == '\\' && args[i + 1] == 't'){
						line[ptr] = '\t';
						i++;
					}
					else
						line[ptr] = args[i];
					ptr++;
				}
				printf("%s\n", line);
			}

			// If the flag is anything other than -e or -n it will be an invalid flag.

			else{
				printf("Error: Invalid flag!\n\n");
				return 1;
			}
		}

		else{
			printf("Error: Invalid flag!\n\n");
			return 1;
		}

	}

    // HELP COMMAND

    // All the commands which are available in this minishell are stored in a file called help.txt.

	else if (strcmp(cmd, "help") == 0){
		FILE *help = fopen("help.txt", "r");

		// Including an if statement just in case help.txt is empty.

		if (help == NULL){
			perror("Error");
			printf("\n");
			return 1;
		}

		char *data = (char*)malloc(sz * sizeof(char));

		// Printing all items from the help.txt file.

		while (fgets(data, sz, help) != NULL){
			printf("%s", data);
		}
		fclose(help);
	}

    // HISTORY COMMAND

    // History command has a flag, -clear. If history command is followed by argument, that would be invalid.

	else if (strcmp(cmd, "history") == 0){
		if (strlen(flag) == 0){
			if (strlen(args) != 0){
				printf("Error: Invalid command!\n");
				return 1;
			}

			FILE *history = fopen("history.txt", "r");

			// Incase history.txt is empty.

			if(history == NULL){
				perror("Error");
				return 1;
			}

			// Printing history.

			char *line = (char*)malloc(sz * sizeof(char));
			while(fgets(line, sz, history) != NULL){
				printf("%s", line);
			}

			fclose(history);
		}

		// If flag is -clear, it should not be followed by any arguments.

		else{
			if (strcmp(flag, "clear") == 0){
				if (strlen(args) != 0){
					printf("Error: No arguments expected for this command!\n");
					return 1;
				}

				FILE *history = fopen("history.txt", "w");

				if(history == NULL){
					perror("Error");
					printf("\n");
					return 1;
				}

				fprintf(history, "%c", ' ');
				fclose(history);
			}

			else
				printf("Error: Invalid command!\n");
		}
	}

    // PWD COMMAND

    // It should not have a flag or argument.

	else if (strcmp(cmd, "pwd") == 0){
		if (strlen(flag) != 0 || strlen(args) != 0){
			printf("Error: Invalid command!\n");
			return 1;
		}

		char *dir = (char*)malloc(PATH_MAX * sizeof(char));

		if (getcwd(dir, PATH_MAX) == NULL){
			perror("Error");
			printf("\n");
			return 1;
		}
		printf("%s\n", dir);
	}

	// If the command is not any of these builtin commands, we will go to ext_cmds function.

	else{
		ext_cmds(cmd, flag, args1, args, args1_len, flag_len);
    }

	return 1;
}

// Shell function. It contains implementation of all builtins.

void shell()
{
	int status;

	do {

        // curr dir contains the address of the current working directory.

		char *curr_dir = (char*)malloc(PATH_MAX * sizeof(char));
		getcwd(curr_dir, PATH_MAX);

		// To print the prompt of the shell, and the name of the user etc before the $ sign.

		printf("\033[0;33m");
		printf("%s", curr_dir);
		printf("\033[0m");
		printf("$ ");

		// We are declaring input of memory size sz(100) * sizeof(char). Then using fgets to take input. Here I am assuming that input will not be of more than 100 characters.

		char *input = (char*)malloc(sz * sizeof(char));
		fgets(input, sz, stdin);

		char *cmd, *flag, *args;

		// Calling the extract_cmds function for input.

		char **commands = (char**)malloc(sz * sizeof(char*));
		commands = extract_cmds(input);

		// Again, storing current working directory in dir.

		char *dir = (char*)malloc(PATH_MAX * sizeof(char));
		getcwd(dir, PATH_MAX);

		// The history is stored in a text file called history.txt. Now we are adding to the history.

		FILE *history = fopen("history.txt", "a+");

		if(history == NULL) {
			printf("%s\n", "Error: Couldn't load history.\n");
		}

		else {
			fprintf(history, "%s", input);
			fclose(history);
		}

        // Declaring three variables, cmd, flag and args to store command, flag and argument respectively.

		for (int i = 0; i < num_cmds; i++){
			cmd = (char*)malloc(sz * sizeof(char));
			flag = (char*)malloc(sz * sizeof(char));
			args = (char*)malloc(sz * sizeof(char));

			int token_ptr = 0, cmd_ptr = 0, flag_ptr = 0,args_ptr = 0;

			char* token = commands[i];

			// Again, while loop to ignore the leading white spaces.

			while(token[token_ptr] != '\0' && token[token_ptr] == ' '){
				token_ptr++;
			}

            // Storing commands in cmd.

			while (token[token_ptr] != '\0' && token[token_ptr] != ' '){
				cmd[cmd_ptr] = token[token_ptr];
				cmd_ptr++;
				token_ptr++;
			}

			cmd[cmd_ptr] = '\0';

			// If cmd is not empty, ending the character array with \0.

			if (cmd_ptr > 0){
				if (cmd[cmd_ptr - 1] == '\n')
					cmd[cmd_ptr - 1] = '\0';
			}

			// Ensuring that if there are any capital letters, they are converted to lowercase.

			for (int i = 0; cmd[i] != '\0'; i++)
				cmd[i] = tolower(cmd[i]);

            // Loop to ignore white space between command and flag.

			while (token[token_ptr] != '\0' && token[token_ptr] == ' '){
				token_ptr++;
            }

            // If we encounter a '-' then it is a flag.

			if (token[token_ptr] == '-'){
				token_ptr++;

				while (token[token_ptr] != '\0' && token[token_ptr] != ' '){
					flag[flag_ptr] = token[token_ptr];
					flag_ptr++;
					token_ptr++;
				}
			}

			// Again, ignoring whitespace between flag and argument.

			while(token[token_ptr] != '\0' && token[token_ptr] == ' '){
				token_ptr++;
            }

            // Storing argument in args.

            while(token[token_ptr] != '\0'){
                    args[args_ptr] = token[token_ptr];
                    token_ptr++;
                    args_ptr++;
            }

			// Next two if statements are to end args and flag character arrays with \0, if they are not empty.

			if(args_ptr > 0){
				if(args[args_ptr - 1] == '\n'){
					args[args_ptr - 1] = '\0';
				}
            }

			if(flag_ptr > 0){
				if(flag[flag_ptr - 1] == '\n'){
					flag[flag_ptr - 1] = '\0';
				}
			}

			// Ensuring that if there are any capital letters, they are converted to lowercase.

			for (int i = 0; flag[i] != '\0'; i++){
				flag[i] = tolower(flag[i]);
            }

            char temp[sz];
            char* args1[sz];
            int args1_ptr=0,i=0;

            while(args[i]!='\0'){
                temp[i]=args[i];
                i++;
            }

            temp[i]='\0';
            i++;

            char* token1 = strtok(temp," ");

            while(token1!=NULL){
                args1[args1_ptr]=token1;
                args1_ptr++;
                token1 = strtok(NULL," ");
            }

            // Status variable is to execute the command.

			status = execute(cmd, flag, args1, args, args1_ptr, flag_ptr);

			if (status == 0)
				break;
		}

	} while (status);
}



// Main function

int main(int argc, char *argv[])
{
	printf("\n-------------------------------------\n");
	printf("Welcome to my Linux Shell\n");
	printf("-------------------------------------\n\n");

	printf("-> Type commands and arguments, and hit enter.\n");
	printf("-> Type 'help' command to see the list of all commands that can be executed here.\n\n");

	// Calling shell function

	shell();


	return 0;
}

// -----------------------------------------------------------------------------



























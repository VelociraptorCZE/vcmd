/* vcmd v0.4
 * Copyright (C) Simon Raichl 2018
 * MIT License
 * Use this as you want, share it as you want, do basically whatever you want with this :)
*/

#define MAX_BUFFER_LENGTH 8192
#define MAX_CMD_LENGTH 1024
#define MAX_DIR_LENGTH 512
#define MAX_PARAMS_LENGTH 128
#define HELP_LENGTH 50

struct CMD {
	int i;
	char command[MAX_CMD_LENGTH];
};

char *info = "vcmd - type help for available commands\nVersion 0.4\nCopyright (C) Simon Raichl 2018, MIT license\n";

//HELP

char *help[HELP_LENGTH] =
{
"\n-----------------HELP-----------------\nCOMMANDS:\n",
"calc - does the math operation with two numbers, example: calc 9 / 5",
"clear - clears a console window",
"d - does the operations with directories, d -m to create folder, d -r to remove folder",
"exit - kills this cmd",
"f - does the operations with files, f -rd to read, f -r to remove, f -m to create, f -w to write",
"help - shows this list",
"l - gets a directory content",
"print - prints a string to the console",
"wait - waits for user key input",
"r - runs a program",
"s - runs a script from the external file",
"* - global command, * -rn to rename file or directory"
};

void helpStack(){
	int i = 0;
	while (i < HELP_LENGTH){
		printf("%s\n", help[i]);
		i++;
	}
}

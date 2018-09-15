/* vcmd v0.2
 * Copyright (C) Simon Raichl 2018
 * MIT Licence
 * Use this as you want, share it as you want, do basically whatever you want with this :)
*/
#define MAX_CMD_LENGTH 1024
#define MAX_DIR_LENGTH 512
#define MAX_PARAMS_LENGTH 12
#define HELP_LENGTH 50

char *info = "vcmd - type help for available commands\nVersion 0.2\nCopyright (C) Simon Raichl 2018, MIT license\n";

//HELP

char *help[HELP_LENGTH] = { 
"\nHELP-----------------\nCOMMANDS:",
"calc - does a math operation with two numbers, example: calc 9 / 5",
"clear - clears a console window",
"d - does an operations with directories, d -m to create folder, d -r to remove folder",
"help - shows this list",
"l - gets a directory content",
"r - runs a program"
};

void helpStack(){
	int i = 0;
	while (i < HELP_LENGTH){
		printf("%s\n", help[i]);
		i++;
	}
}

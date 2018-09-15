/* vcmd v0.2
 * Copyright (C) Simon Raichl 2018
 * MIT Licence
 * Use this as you want, share it as you want, do basically whatever you want with this :)
*/
int run() {
	char d[MAX_DIR_LENGTH];
  	GetCurrentDir(d, MAX_DIR_LENGTH);
  	printf("\n%s>", d);
  
	char input[MAX_CMD_LENGTH];
	gets(input);
	if (strcmp(input, "") != 0) {
		int i = 0;
		char *command[MAX_PARAMS_LENGTH];
		char *part;
		part = strtok(input, " ");
		command[i] = part;
		i++;
		while (part != NULL) {
			part = strtok(NULL, " ");
			if (i < MAX_PARAMS_LENGTH) {
				command[i] = part;
				i++;
			}
		}
		if(strcmp(input, "help") == 0) {
			helpStack();
		} 
		else if(strcmp(input, "exit") == 0) {
			return 0;
		}
		else if (strcmp(command[0], "calc") == 0) {
			calc(command);
		}
		else if (strcmp(command[0], "clear") == 0) {
			clear();
		}
		else if (strcmp(command[0], "l") == 0) {
			getDir(command);
		}
		else if (strcmp(command[0], "d") == 0) {
			dirOperation(command);
		}
		else if (strcmp(command[0], "r") == 0) {
			runProgram(command);
		}
		else {
			printf("Not recognized command '%s'", input);
		}
	}
	printf("\n");
	run();
}

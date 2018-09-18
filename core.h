/* vcmd v0.5
 * Copyright (C) Simon Raichl 2018
 * MIT License
 * Use this as you want, share it as you want, do basically whatever you want with this :)
*/

int run(char external[MAX_CMD_LENGTH]) {
  	
	char input[MAX_CMD_LENGTH];
  	
  	if (strcmp(external, "void") == 0){ 	
	  	char d[MAX_DIR_LENGTH];
  		GetCurrentDir(d, MAX_DIR_LENGTH);
  		printf("\n%s>", d);	
		gets(input);
	}
	else{
		strcpy(input, external);
	}
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
		else if (strcmp(command[0], "l") == 0 || strcmp(command[0], "ll") == 0 || strcmp(command[0], "ls") == 0) {
			getDir(command);
		}
		else if (strcmp(command[0], "d") == 0) {
			dirOperation(command);
		}
		else if (strcmp(command[0], "r") == 0) {
			runProgram(command);
		}
		else if (strcmp(command[0], "f") == 0) {
			fileOperation(command);
		}
		else if (strcmp(command[0], "print") == 0) {
			print(command);
		}
		else if (strcmp(command[0], "wait") == 0) {
			wait();
		}
		else if (strcmp(command[0], "var") == 0) {
			declareVariable(command);
		}
		else if (strcmp(command[0], "s") == 0) {
			runScript(command);
		}	
		else if (strcmp(command[0], "*") == 0) {
			other(command);
		}
		else {
			printf("Not recognized command '%s'", input);
		}
	}
	if (strcmp(external, "void") == 0){
		run(external);	
	}
}

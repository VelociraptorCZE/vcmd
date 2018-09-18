/* vcmd v0.5
 * Copyright (C) Simon Raichl 2018
 * MIT License
 * Use this as you want, share it as you want, do basically whatever you want with this :)
*/

void calc(char *c[]) {
	float num1 = 0;
	float num2 = 0;
	num1 = atof(getVarValue(c[1])) + atof(c[1]);
	num2 = atof(getVarValue(c[3])) + atof(c[3]);
	float result;
	int e = 0;
	if (strcmp(c[2], "+") == 0) {
		result = num1 + num2;
	}
	if (strcmp(c[2], "-") == 0) {
		result = num1 - num2;
	}
	if (strcmp(c[2], "*") == 0) {
		result = num1 * num2;
	}
	if (strcmp(c[2], "/") == 0) {
		if (num2 != 0){
			result = num1 / num2;
		}
		else{
			printf("It's impossible to divide by zero!");
			e = 1;
		}
	}
	if (!e){
		printf("%.2f", result);
	}
}

void clear(){
	system("@cls||clear");
}

void other(char *c[]){
	if (strcmp(c[1], "-rn") == 0){
		rename(c[2], c[3]);
	}
	if (strcmp(c[1], "var") == 0){
		dumpVars();
	}
}

void print(char *c[]){
	int i = 1;
	while(i < MAX_PARAMS_LENGTH && c[i] != NULL){
		if (c[i][0] == '$'){
			c[i] = getVarValue(c[i]);
		}
		printf("%s ", c[i]);
		i++;
	}
	printf("\n");
}

void dirOperation(char *c[]){
	if (c[1] != '\0'){
		if (strcmp(c[1], "-m") == 0){
			mkdir(c[2]);
		}
		else if (strcmp(c[1], "-r") == 0){
			rmdir(c[2]);
		}
	}
}

void declareVariable(char *c[]){
	if (varId < MAX_NUMBER_OF_VARIABLES){
		int i = 0;
		int e = 0;
		int eid = 0;
		while(i < varId){
			if (strcmp(var[i].name, c[1]) == 0){
				e = 1;
				eid = i;
				break;
			}
			i++;
		}
		if (!e){
			var[varId].name = c[1];
			var[varId].value = c[2];
			varId++;
		}
		else{
			var[eid].name = c[1];
			var[eid].value = c[2];
			printf("\nVariable has been overridden successfully, value: %s\n", c[2]);
		}	
	}
	else{
		printf("\nYou've already assigned maximum number of variables, command terminated!\n");
	}
}

void runScript(char *c[]){
	if (c[1][0] == '$'){
		c[1] = getVarValue(c[1]);
	}
	readFile(c[1], 1);
}

void fileOperation(char *c[]){
	FILE *f;
	if (c[2][0] == '$'){
		c[2] = getVarValue(c[2]);
	}
	if (strcmp(c[1], "-rd") == 0){
		readFile(c[2], 0);
	}
	else if (strcmp(c[1], "-r") == 0){
		remove(c[2]);
	}
	else if (strcmp(c[1], "-m") == 0){
		fopen(c[2], "ab+");
	}
	else if (strcmp(c[1], "-w") == 0){
		f = fopen(c[2], "w");
		printf("Write text: ");
		char input[MAX_BUFFER_LENGTH];
		gets(input);
		fprintf(f, "%s", input);
		fclose(f);
	}
}

void wait(){
	printf("\nPress any key to continue...\n");
	getch();
}

void getDir(char *c[]){
	struct dirent *dp;
	if (c[1] == '\0'){
		c[1] = ".";
	}
	else if (c[1][0] == '$'){
		c[1] = getVarValue(c[1]);
	}
	DIR *d = opendir(c[1]);
	if (d == NULL){
		printf("Invalid directory");
	}
	while ((dp = readdir(d)) != NULL){
	 	printf("%s\n", dp->d_name); 
	}
    closedir(d);
}

void runProgram(char *c[]){
	system(c[1]);
}

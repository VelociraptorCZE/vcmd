/* vcmd v0.2
 * Copyright (C) Simon Raichl 2018
 * MIT Licence
 * Use this as you want, share it as you want, do basically whatever you want with this :)
*/
void calc(char *c[]) {
	float num1 = atof(c[1]);
	float num2 = atof(c[3]);
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

void getDir(char *c[]){
	struct dirent *dp;
	if (c[1] == '\0'){
		c[1] = ".";
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

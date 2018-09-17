/* vcmd v0.4
 * Copyright (C) Simon Raichl 2018
 * MIT License
 * Use this as you want, share it as you want, do basically whatever you want with this :)
*/

void readFile(char file[], int cmd){
	struct CMD C;
	C.i = 0;
	char ch;
	FILE *f = fopen(file, "r");
	while((ch = fgetc(f)) != EOF){
		if (cmd){
			if (ch != '\n'){
				C.command[C.i] = ch;
				C.i++;
			}
			else{
				C.i = 0;
				int i = 0;
				run(C.command);	
				while(i < sizeof(C.command)){
					C.command[i] = 0;
					i++;
				}
			}
		}
		else{
			printf("%c", ch);
		}
    }
    fclose(f);
}

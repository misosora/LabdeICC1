/*************************************************************************************************
(                _                USP-Universidade de São Paulo                 _                )
(    __   ___.--'_`.  ICMC-Instituto de Ciências Matemáticas e de Computação  .'_`--.___   __    )
(   ( _`.'. -   'o` ) ====================================================== ( 'o`   - .`.'_ )   )
(   _\.'_'      _.-'           Bacharelado em Ciências de Computação          `-._      `_`./_   )
(  ( \`. )    //\`                            2020/1                            '/\\    ( .'/ )  )
(   \_`-'`---'\\__, ========================================================== ,__//`---'`-'_/   )
(    \`        `-\           __    __                                           /-´        ´/    )
(     `                     ( 0)__( 0)  Gabriela Satie Faria Nishimi                       ´     )
(                           /   ''   \     ____________________                                  )
(                          ( ´´  3 ´´ )  < Número USP: 11892820)                                 )
(                           \        /                                                           )
(                           /___>o<__\                                                           )
(                           uuu    uuu                                                           )
( Programa: Nome Bibliográfico                                                                   )
*************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define READLINE_BUFFER 4096

char *readLine(FILE *stream) {
	char *string = NULL;
	int i = 0;

	do {
		if (i % READLINE_BUFFER == 0) {
			string = (char *) realloc(string,(i / READLINE_BUFFER + 1) * READLINE_BUFFER);
		}
		string[i] = fgetc(stream);
		i++;
	} while (string[i-1] != '\n' && string[i-1] != EOF);

	if (i >= 2 && string[i - 2] == '\r') {
		string[i - 2] = '\0';
		string = (char* ) realloc(string, i-1);
	} else {
		string[i-1] = '\0';
		string = (char* ) realloc(string, i);
	}

	return string;
}

void printName(char *name){	
	char *lastName = strrchr(name, ' ');
	
	int len = strlen(name);
	int lastLen = strlen(lastName);

	for(int i = 1; i < lastLen; i++){
		if(lastName[i] >= 65 && lastName[i] <= 90){
			printf("%c", lastName[i]);
		} else {
			lastName[i] -= 32;
			printf("%c", lastName[i]);
		}
	}
	printf(", ");
	
	for(int j = 0; j < len-lastLen; j++){
		printf("%c", name[j]);
	}
	printf("\n");

	return;
}

int main(int argc, char *argv[]){
	char *name = readLine(stdin);

	printName(name);
	
	free(name);
	return 0;
}

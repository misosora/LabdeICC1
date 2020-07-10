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
( Programa: Adicionando Sobrenomes                                                               )
*************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READLINE_BUFFER 4096

int count = 0;

char *readLine(FILE *stream) {
	char *string = NULL;
	int i = 0;

	do {
		if (i % READLINE_BUFFER == 0) {
			string = (char *) realloc(string, (i / READLINE_BUFFER + 1)*READLINE_BUFFER);
		}
		string[i] = fgetc(stream);
		i++;
	} while (string[i-1] != '\n' && string[i-1] != EOF);

	if (i >= 2 && string[i-2] == '\r') {
		string[i-2] = '\0';
		string = (char *) realloc(string, i-1);
	} else {
		string[i-1] = '\0';
		string = (char *) realloc(string, i);
	}

	return string;
}

void readNames(char **names){
	while(!feof(stdin)){
		names[count] = readLine(stdin);

		for(int j = 0; j < strlen(names[count]); j++){
			if(names[count][j] == '$'){
				names[count][j] = '\0';
				return;
			}
		}

		count++;
	}

	return;
}

void addLastname(char **names){
	char *lastname = (char *) malloc(50*sizeof(char));

	for(int i = 0; i < count+1; i++){
		if(i%2 == 0){
			lastname = strrchr(names[i], ' ');
		}else{
			strcat(names[i], lastname);
		}
	}

	return;
}

void printNames(char **names){
	for(int i = 0; i < count+1; i++){
		printf("%s\n", names[i]);
	}

	return;
}

int main(int argc, char *argv[]){
	char **names = (char **) malloc(50*sizeof(char *));
	readNames(names);
	
	addLastname(names);
	printNames(names);

	free(names);
	return 0;
}

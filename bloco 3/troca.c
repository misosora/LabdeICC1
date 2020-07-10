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
( Programa: Trocando Sobrenomes                                                                  )
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

void removeName(char *string, char *substring){	
	int len = strlen(string);
	int subLen = strlen(substring);
	
	int end = len-subLen;

	string[end] = '\0';	

	return;
}

void separateNames(char **names, char **splitNames, char **lastNames){
	for(int i = 0; i < count+1; i++){	
		strcpy(splitNames[i], names[i]);
		lastNames[i] = strrchr(names[i], ' ');
		removeName(splitNames[i], lastNames[i]);
	}
	
	return;
}

void switchNames(char **splitNames, char **lastNames){
	int aux = count;

	for(int i = 0; i < count+1; i++){
		printf("%s%s\n", splitNames[i], lastNames[aux]);
		aux--;
	}

	return;
}

int main(int argc, char *argv[]){
	char **names = (char **) malloc(210*sizeof(char *));
	readNames(names);

	char **splitNames = (char **) malloc((count+1)*sizeof(char *));
	for(int i = 0; i < count+1; i++){
		splitNames[i] = (char *) malloc(210*sizeof(char));
	}

	char **lastNames = (char **) malloc((count+1)*sizeof(char *));	
	for(int i = 0; i < count+1; i++){
		lastNames[i] = (char *) malloc(210*sizeof(char));
	}

	separateNames(names, splitNames, lastNames);
	switchNames(splitNames, lastNames);

	free(names);
	free(splitNames);
	free(lastNames);

	return 0;
}

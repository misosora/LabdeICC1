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
( Programa: Matriz de Nomes                                                                      )
*************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READLINE_BUFFER 4096

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

void readInput(char **names){
	for(int i = 0; i < 5; i++){
		names[i] = readLine(stdin);
	}

	return;
}

int comparator(const void *a, const void *b){
	const char **ia = (const char **) a;
	const char **ib = (const char **) b;

	return strcmp(*ia, *ib);
}

void sortArray(char **names){
	qsort(names, 5, sizeof(char *), comparator);

	return;
}

void printNames(char **names){
	for(int i = 0; i < 5; i++){
		printf("%s\n", names[i]);
		free(names[i]);
	}

	free(names);
	return;
}

int main(int argc, char *argv[]){
	char **names = (char **) malloc(5*sizeof(char *));
	
	readInput(names);
	sortArray(names);
	printNames(names);

	return 0;
}

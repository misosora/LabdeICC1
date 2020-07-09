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
( Programa: Particionamento de Strings                                                           )
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

void separaString(char *nome, char **fraseParticionada){
	char *token;
	token = strtok(nome, " ");

	while(token != NULL){
		fraseParticionada[count] = token;
		token = strtok(NULL, " ");
		count++;
	}

	return;
}

void printFrase(char **fraseParticionada){
	for(int i = 0; i < count; i++){
		printf("%s\n", fraseParticionada[i]);
	}

	return;
}

int comparator(const void *a, const void *b){
	const char **ia = (const char **) a;
	const char **ib = (const char **) b;

	return strcmp(*ia, *ib);
}

void printFraseEmOrdem(char **fraseParticionada){
	for(int i = 0; i < count; i++){
		for(int j = 0; j < strlen(fraseParticionada[i]); j++){
			if(fraseParticionada[i][j] <= 90 && fraseParticionada[i][j] >= 65){
				fraseParticionada[i][j] += 32;
			}
		}
	}

	qsort(fraseParticionada, count, sizeof(char *), comparator);
	
	for(int i = 0; i < count; i++){
		printf("%s\n", fraseParticionada[i]);
	}
}

int main(int argc, char *argv[]){
	char *frase = readLine(stdin);
	int op;
	scanf("%d", &op);

	char **fraseParticionada = (char **) malloc(50*sizeof(char *));
	for(int i = 0; i < 50; i++){
		fraseParticionada[i] = (char *) malloc(50*sizeof(char));
	}
	
	separaString(frase, fraseParticionada);

	switch(op){
		case 1:
			printFrase(fraseParticionada);
			break;
		case 2:
			printFraseEmOrdem(fraseParticionada);
			break;
	}
	
	free(fraseParticionada);
	free(frase);

	return 0;
}

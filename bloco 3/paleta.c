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
( Programa: Paleta de Cores                                                                      )
*************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void readPalette(int **palette, int **newPalatte){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 3; j++){
			scanf("%d", &palette[i][j]);
			newPalatte[i][j] = palette[i][j];
		}
	}

	return;
}

void mixColors(int firstPos, int secondPos, int resultPos, int **newPalatte){
	int red, green, blue;

	red = newPalatte[firstPos][0]/2 + newPalatte[secondPos][0]/2 + newPalatte[resultPos][0];
	green = newPalatte[firstPos][1]/2 + newPalatte[secondPos][1]/2 + newPalatte[resultPos][1];
	blue = newPalatte[firstPos][2]/2 + newPalatte[secondPos][2]/2 + newPalatte[resultPos][2];

	if(red > 255){
		red = 255;
	}
	if(green > 255){
		green = 255;
	}
	if(blue > 255){
		blue = 255;
	}

	newPalatte[resultPos][0] = red;
	newPalatte[resultPos][1] = green;
	newPalatte[resultPos][2] = blue;

	return;
}

void printPalettes(int **palette, int **newPalatte){
	printf("Start:\n");
	for(int i = 0; i < 6; i++){
		printf("Color(%d): [\t%d\t%d\t%d\t]\n", i, palette[i][0], palette[i][1], palette[i][2]);
	}
	
	printf("\nResult:\n");
	for(int i = 0; i < 6; i++){
		printf("Color(%d): [\t%d\t%d\t%d\t]\n", i, newPalatte[i][0], newPalatte[i][1], newPalatte[i][2]);
	}

	return;
}

void freeArray(int **array){
	for(int i = 0; i < 6; i++){
		free(array[i]);
	}
	free(array);

	return;
}

int main(int argc, char *argv[]){
	int firstPos, secondPos, resultPos;
	scanf("%d %d %d", &firstPos, &secondPos, &resultPos);

	int **palette = (int **) malloc(6*sizeof(int *));
	for(int i = 0; i < 6; i++){
		palette[i] = (int *) malloc(3*sizeof(int));
	}

	int **newPalatte = (int **) malloc(6*sizeof(int *));
	for(int i = 0; i < 6; i++){
		newPalatte[i] = (int *) malloc(3*sizeof(int));
	}

	readPalette(palette, newPalatte);
	mixColors(firstPos, secondPos, resultPos, newPalatte);
	printPalettes(palette, newPalatte);
	
	freeArray(palette);
	freeArray(newPalatte);
	return 0;
}

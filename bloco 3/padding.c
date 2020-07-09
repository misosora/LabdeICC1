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
( Programa: Padding de Imagens                                                                   )
*************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void freeArray(int **array, int altura){
	for(int i = 0; i < altura; i++){
		free(array[i]);
	}
	free(array);

	return;
}

void adicionaBorda(int **imagemOriginal, int altura, int largura, int borda){
	int novaAltura = altura + borda*2;
	int novaLargura = largura + borda*2;
	
	int **imagemFinal = (int **) calloc(novaAltura, sizeof(int *));
	for(int i = 0; i < novaAltura; i++){
		imagemFinal[i] = (int *) calloc(novaLargura, sizeof(int));
	}

	for(int i = 0; i < altura; i++){
		for(int j = 0; j < largura; j++){
			imagemFinal[i+borda][j+borda] = imagemOriginal[i][j];
		}
	}

	for(int i = 0; i < novaAltura; i++){
		for(int j = 0; j < novaLargura; j++){
			if(j == novaLargura-1){
				printf("%d \n", imagemFinal[i][j]);
			}else{
				printf("%d ", imagemFinal[i][j]);
			}
		}
	}
	printf("\n");
	for(int i = 0; i < altura; i++){
		for(int j = 0; j < largura; j++){
			if(j == largura-1){
				printf("%d \n", imagemOriginal[i][j]);
			}else{
				printf("%d ", imagemOriginal[i][j]);
			}
		}
	}

	freeArray(imagemFinal, novaAltura);

	return;
}

int main(int argc, char *argv[]){
	int largura, altura;
	scanf("%d %d", &largura, &altura);
	
	int **imagemOriginal = (int **) malloc(altura*sizeof(int *));
	for(int i = 0; i < altura; i++){
		imagemOriginal[i] = (int *) malloc(largura*sizeof(int));
	}

	for(int i = 0; i < altura; i++){
		for(int j = 0; j < largura; j++){
			scanf("%d", &imagemOriginal[i][j]);
		}
	}

	int borda;
	scanf("%d", &borda);

	adicionaBorda(imagemOriginal, altura, largura, borda);
	freeArray(imagemOriginal, altura);

	return 0;
}

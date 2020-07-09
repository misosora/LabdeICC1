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
( Programa: Ataque e Tipos                                                                       )
*************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void lerTiposAtaques(int tipos, double **matriz, double **ataque){
	for(int i = 0; i < tipos; i++){
		for(int j = 0; j < tipos; j++){
			scanf("%lf", &matriz[i][j]);
		}
	}
	
	for(int i = 0; i < tipos; i++){
		for(int j = 0; j < 2; j++){
			scanf("%lf", &ataque[i][j]);
		}
	}
	
	int check;
	scanf("%d", &check);

	return;
}

void melhorAtaque(int tipos, double **matriz, double **ataque, int inimigo){
	int indice = 0;
	double dano, maiorDano = 0;
	
	for(int i = 0; i < tipos; i++){
		dano = ataque[i][0]*matriz[i][inimigo];

		if(dano > maiorDano){
			maiorDano = dano;
			indice = i;
		}
	}
	
	printf("O melhor ataque possui indice %d e dano %.2lf\n", indice, maiorDano);
	
	return;
}

void freeArray(int tipos, double **matriz){
	for(int i = 0; i < tipos; i++){
		free(matriz[i]);
	}
	free(matriz);
	
	return;
}

int main(int argc, char *argv[]){
	int tipos;
	scanf("%d", &tipos);

	double **matriz = (double **) malloc(tipos*sizeof(double *));
	double **ataque = (double **) malloc(tipos*sizeof(double *));
	
	for(int i = 0; i < tipos; i++){
		matriz[i] = (double *) malloc(tipos*sizeof(double));
		ataque[i] = (double *) malloc(2*sizeof(double));
	}

	lerTiposAtaques(tipos, matriz, ataque);

	int inimigo;
	scanf("%d", &inimigo);

	melhorAtaque(tipos, matriz, ataque, inimigo);

	freeArray(tipos, matriz);
	freeArray(tipos, ataque);
	return 0;
}

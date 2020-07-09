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
( Programa: Corra para a base                                                                    )
*************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void lerMapa(int **mapa, int linhas, int colunas){
	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			scanf("%d", &mapa[i][j]);
		}
	}
	
	return;
}

int calcDistancia(int personagemX, int personagemY, int baseX, int baseY){
	double dx, dy, distancia;
	int x, y;
	
	x = personagemX - baseX;
	y = personagemY - baseY;
	
	if(baseX >= personagemX){
		x = baseX - personagemX;
	}
	if(baseY >= personagemY){
		y = baseY - personagemY;
	}

	dx = pow(x, 2);
	dy = pow(y, 2);

	distancia = sqrt(dx+dy);

	return distancia;
}

void freeArray(int **array, int linhas){
	for(int i = 0; i < linhas; i++){
		free(array[i]);
	}
	free(array);

	return;
}

int main(int argc, char *argv[]){
	int linhas, colunas;
	scanf("%d %d", &linhas, &colunas);
	
	int personagemX, personagemY;
	double movimento;
	scanf("%d %d %lf", &personagemX, &personagemY, &movimento);

	int **mapa = (int **) malloc(linhas*sizeof(int *));
	for(int i = 0; i < linhas; i++){
		mapa[i] = (int *) malloc(colunas*sizeof(int));
	}

	lerMapa(mapa, linhas, colunas);
	
	int baseX, baseY;
	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			if(mapa[i][j] == 1){
				baseX = i;
				baseY = j;
			}
		}
	}
	
	double distancia = calcDistancia(personagemX, personagemY, baseX, baseY);
	if(distancia <= movimento){
		printf("Voce escapou!\n");
	}else{
		printf("Game Over!\n");
	}
	
	freeArray(mapa, linhas);
	return 0;
}

/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Gabriela Satie (11892820)                     |
 *******************************************************************************
 Programa que fornece a posição final de um robô após uma série de comandos
 *******************************************************************************/
#include <stdio.h> // Utilização das funções scanf() e printf()
#include <string.h> // Utilização da função strlen()

int main(int argc, char *argv[]){
	
	// Declaração do vetor comandos[200], que irá guardar todos os caracteres
	// digitados pelo usuário
	char comandos[200];
	scanf("%s", comandos);

	// Declaração e inicialização da variável posicao, que irá receber as
	// posições do robô de acordo com os comandos digitados
	int posicao = 0;

	// For que irá ler todos os caracteres contidos em comandos[200]
	for (int i = 0; i < strlen(comandos); i++){
		
		// Se o comando for para virar à direita, posicao receberá mais um
		if (comandos[i] == 'D'){
			posicao += 1;
		}

		// Se o comando for para virar à esquerda, posicao receberá menos um
		if (comandos[i] == 'E'){
			posicao -= 1;
		}
		
		// Se posicao for 4 ou -4, significa que está no norte (já passou por
		// todas as posições), então seu valor será o inicial (0)
		if (posicao == 4 || posicao == -4){
			posicao = 0;
		}
	}
	
	// Se posicao for igual a zero, o robô está virado para a posição inicial,
	// ou seja, para o norte
	if (posicao == 0){
		printf("Norte\n");
	}

	// Se posicao for igual a 1 ou -3, o robô está virado para o leste
	if (posicao == 1 || posicao == -3){
		printf("Leste\n");
	}

	// Se posicao for igual a 2 ou -2, o robô está virado para o sul
	if (posicao == 2 || posicao == -2){
		printf("Sul\n");
	}

	// Se posicao for igual a 3 ou -3, o robô está virado para o oeste
	if (posicao == 3 || posicao == -1){
		printf("Oeste\n");
	}

	return 0;
}

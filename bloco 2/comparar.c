/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Gabriela Satie (11892820)                     |
 *******************************************************************************
 Programa que pode executar cinco funções de comparação entre duas palavras
 *******************************************************************************/

#include <stdio.h> // Utilização das funções scanf() e printf()
#include <string.h> // Utilização das funções strlen() e strcomp()

int main(int argc, char *argv[]){
	
	// Declaração e inicialização da variável op, que irá guardar a opção (1-5)
	// escolhida pelo usuário para comparação
	int op = 0;
	scanf("%d", &op);

	// Declaração de dois vetores (word1[10] e word2[10]) que guardarão as palavras
	// digitadas pelo usuário
	char word1[10], word2[10];
	
	scanf("%s", word1);
	scanf("%s", word2);
	
	// For que irá transformar todas as letras das palavras em minúsculas para
	// facilitar a comparação (utilizando valores da tabela ASCII)
	for (int aux = 0; aux < 10; aux++){
		if (word1[aux] >= 65 && word1[aux] <= 90){
			word1[aux] += 32;
		}
		if (word2[aux] >= 65 && word2[aux] <= 90){
			word2[aux] += 32;
		}
	}		

	// Declaração e inicialização da variável resultado, que irá guardar o valor
	// retornado pela função strcomp()
	int resultado = 0;

	// Declaração e inicialização das variáveis soma1 e soma2, que irão guardar
	// o valor da soma dos caracteres (A = 0 - Z = 25)
	int soma1 = 0, soma2 = 0;
	
	// Declaração da variável letra, que, se forem escolhidas as opções 4 e 5, irá
	// guardar a letra escolhida para comparação
	char letra;

	// Declaração e inicialização das variáveis repeticao1 e repeticao2, que irão
	// guardar quantas vezes uma determinada letra se repete nas palavras
	int repeticao1 = 0, repeticao2 = 0;
	
	// Declaração e inicialização das variáveis aparicao1 e aparicao2, que irão
	// guardar a posição em que uma determinada letra aparece nas palavras
	int aparicao1 = 0, aparicao2 = 0;

	// Switch de acordo com a opção (1-5) digitada pelo usuário
	switch (op){
		
		// 1 - Qual palavra tem maior tamanho
		case 1:
			
			// Utilização da função strlen() para determinar o tamanho das
			// 'palavras e compará-los
			if (strlen(word1) > strlen(word2)){
				printf("1\n");
			} else if (strlen(word1) == strlen(word2)){
				printf("0\n");
			} else {
				printf("2\n");
			}
			
			break;
		
		// 2 - Ordem Alfabética
		case 2:	
			
			// A variável resultado receberá o valor resultante da comparação
			// de word1 com word2
			resultado = strcmp(word1, word2);

			// Como a função strcmp() retorna um inteiro de acordo com os valores
			// dos caracteres na tabela ASCII:
			if (resultado > 0){ // Se for maior que zero, word1 > word2
				printf("2\n");
			} else if (resultado == 0){ // Se for igual a zero, word1 = word2
				printf("0\n");
			} else { // Se for menor que zero, word1 < word2
				printf("1\n");
			}
			
			break;
		
		// 3 - Qual palavra apresenta maior soma dos valores das letras
		case 3:
			
			// For que irá ler todos os caracteres da word2 e somar seus valores,
			// incrementando a variável soma1
			for (int j = 0; j < strlen(word1); j++){
				soma1 += word1[j] - 97; // 97 => valor de a, então a=0 - z=25
			}
			
			// For que irá ler todos os caracteres da word2 e somar seus valores,
			// incrementando a variável soma2
			for (int j = 0; j < strlen(word2); j++){
				soma2 += word2[j] - 97; // 97 => valor de a, então a=0 - z=25
			}
			
			// Comparação dos valores das somas (soma1 e soma2)
			if (soma1 > soma2){
				printf("1\n");
			} else if (soma1 == soma2){
				printf("0\n");
			} else {
				printf("2\n");
			}
			
			break;
		
		// 4 - Qual das palavras tem mais repetições de uma determinada letra
		case 4:
			
			// Leitura da letra que o usuário escolherá
			scanf(" %c", &letra);

			// Transformação da letra para minúscula (se for maiúscula)
			if (letra >= 65 && letra <= 90){
				letra += 32;
			}

			// For que irá ler todos os caracteres de word1 e incrementar
			// repeticao1 se houver ocorrência da letra escolhida
			for (int k = 0; k < strlen(word1); k++){
				if (word1[k] == letra){
					repeticao1 += 1;
				}
			}
			
			// For que irá ler todos os caracteres de word2 e incrementar
			// repeticao2 se houver ocorrência da letra escolhida
			for (int k = 0; k < strlen(word2); k++){
				if (word2[k] == letra){
					repeticao2 += 1;
				}
			}
			
			// Comparação do número de repetições (repeticao1 e repeticao2)
			if (repeticao1 > repeticao2){
				printf("1\n");
			} else if (repeticao1 == repeticao2){
				printf("0\n");
			} else {
				printf("2\n");
			}
			
			break;
		
		// 5 - Em qual das palavras uma determinada letra aparece primeiro
		case 5:
			
			// Leitura da letra que o usuário escolherá
			scanf(" %c", &letra);
			
			// Transformação da letra para miniscúla (se for maiúscula)
			if (letra >= 65 && letra <= 90){
				letra += 32;
			}
	
			// For que irá ler todos os caracteres de word1 e atualizar aparicao1
			// como a primeira posição em que a letra escolhida aparece
			for (int w = 0; w < strlen(word1); w++){
				if (word1[w] == letra){
					aparicao1 = w;
					break;
				}
			}
			
			// For que irá ler todos os caracteres de word2 e atualizar aparicao2
			// como a primeira posição em que a letra escolhida aparece	
			for (int w = 0; w < strlen(word2); w++){
				if (word2[w] == letra){
					aparicao2 = w;
					break;
				}
			}
			
			// Comparação das posições em que a letra escolhida aparece
			// (aparicao1 e aparicao2)
			if (aparicao1 > aparicao2){
				printf("2\n");
			} else if (aparicao1 == aparicao2){
				printf("0\n");
			} else {
				printf("1\n");
			}
			
			break;
	}
	
	return 0;
}

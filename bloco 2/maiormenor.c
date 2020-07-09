/*Programa para imprimir o maior e o menor número de um conjunto*/

#include <stdio.h> // Utilização das funções scanf() e printf()

int main(int argc, char *argv[]){	
	
	/* Declaração e inicialização da variável N, que representa a quantidade
	de elementos do conjunto */
	int N = 0;
	scanf("%d", &N);

	/* Declaração do vetor valor[N], que guarda os valores 
	inseridos pelo usuário */
	int valor[N];

	/* Declaração da variável auxiliar i e das variáveis maior_valor
	e menor_valor, que guardam o maior e o menor valor, respectivamente */
	int i, maior_valor, menor_valor;
	maior_valor = 0;
	menor_valor = 0;

	/* For que irá registrar os valores inseridos de acordo com o valor N */
	for (i = 0; i < N; i++){
		valor[i] = 0;
		scanf("%d", &valor[i]);
	}
	
	/* Assumimos o maior_valor e o menor_valor como o primeiro elemento do
	conjunto para comparação */
	maior_valor = menor_valor = valor[0];
	
	/* For que irá comparar todos os valores, começando com o segundo
	e o primeiro */
	for (i = 1; i < N; i++){
		/* Se o valor seguinte for maior que o anterior, o maior_valor é
		atualizado */
		if (valor[i] > maior_valor){
			maior_valor = valor[i];
		}
		
		/* Se o valor seguinte for menor que o anterior, o menor_valor é
		atualizado */
		if (valor[i] < menor_valor){
			menor_valor = valor[i];
		}
	}
	
	/* Impressão dos valores máximo e mínimo encontrados */
	printf("max: %d\nmin: %d\n", maior_valor, menor_valor);

	return 0;
}

/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2020/1                                    |
 |                                                                             |
 |                        Autor: Gabriela Satie (11892820)                     |
 *******************************************************************************
 Programa que retorna a menor quantidade possível de moedas como troco
 *******************************************************************************/

#include <stdio.h> // Utilização das funções scanf() e printf()

// Função que calculará o troco, recebendo o valor digitado pelo usuário
// e um vetor vals[6] que guardará a quantidade de moedas de cada valor
void calcTroco(int compras, int vals[6]){	
	
	// Enquanto compras for maior ou igual a 100 centavos (1 real), o vetor
	// vals na posição 0 será incrementado e a cada iteração será subtraído
	// 100 de compras
	while (compras >= 100){
		vals[0] += 1;
		compras -= 100;
	}

	// Enquanto compras for maior ou igual a 50 centavos, o vetor vals na
	// posição 1 será incrementado e a cada iteração será subtraído 50
	// de compras
	while (compras >= 50){
		vals[1] += 1;
		compras -= 50;
	}

	// Enquanto compras for maior ou igual a 25 centavos, o vetor vals na
	// posição 2 será incrementado e a cada iteração será subtraído 25
	// de compras
	while (compras >= 25){
		vals[2] += 1;
		compras -= 25;
	}

	// Enquanto compras for maior ou igual a 10 centavos, o vetor vals na
	// posição 3 será incrementado e a cada iteração será subtraído 10
	// de compras
	while (compras >= 10){
		vals[3] += 1;
		compras -= 10;
	}

	// Enquanto compras for maior ou igual a 5 centavos, o vetor vals na
	// posição 4 será incrementado e a cada iteração será subtraído 5
	// de compras
	while (compras >= 5){
		vals[4] += 1;
		compras -= 5;
	}
	
	// O valor restante após todos os while será a quantidade de moedas
	// de 1 centavo, que será guardada no vetor vals na posição 5
	vals[5] = compras;
}

int main(int argc, char *argv[]){

	// Declaração e inicialização da variável compras, que irá guardar
	// o valor em centavos digitado pelo usuário
	int compras = 0;
	scanf("%d", &compras);

	// Declaração e inicialização do vetor vals[6], que irá guardar as
	// quantidades necessárias de cada moeda
	int vals[6] = {0};
	calcTroco(compras, vals);

	// Impressão das quantidades necessárias de cada moeda
	printf("O valor consiste em %d moedas de 1 real\n", vals[0]);
	printf("O valor consiste em %d moedas de 50 centavos\n", vals[1]);
	printf("O valor consiste em %d moedas de 25 centavos\n", vals[2]);
	printf("O valor consiste em %d moedas de 10 centavos\n", vals[3]);
	printf("O valor consiste em %d moedas de 5 centavos\n", vals[4]);
	printf("O valor consiste em %d moedas de 1 centavo\n", vals[5]);
	
	return 0;
}

/* Programa para verificar a divisibilidade de 30 números por um 31º */

#include <stdio.h> // Utilização das funções scanf() e printf()

int main(int argc, char *argv[]){
	
	/* Declaração e inicialização do vetor numeros[31], que guardará
	os 31 valores digitados pelo usuário */
	int numeros[31] = {0};
	
	int i; // Declaração da variável auxiliar i

	/* For que irá ler todos os números inseridos e guardá-los em suas 
	respectivas posições no vetor numeros[31] */
	for (i = 0; i < 31; i++){
		scanf("%d", &numeros[i]);
	}
	
	/* For que irá analisar todos os 30 primeiro números digitados */
	for (i = 0; i < 30; i++){

		/* Se o número for divisível pelo 31º, ou seja, se o resto da
		divisão desses dois números for zero, ele será impresso */
		if ((numeros[i] % numeros[30]) == 0){
			printf("%d\n", numeros[i]);
		}
	}
	
	return 0;
}

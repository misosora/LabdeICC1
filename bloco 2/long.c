/* Programa para ler um long e imprimir os 8 bytes que o compõem */

#include <stdio.h> // Utilização das funções scanf() e printf()

int main(int argc, char *argv[]){
	
	/* Declaração e inicialização da variável input, que guardará o valor
	digitado pelo usuário */
	long input = 0;
	scanf("%ld", &input);

	/* Declaração e inicialização do vetor byte[8], que guardará os bytes
	que compõem o long */
	unsigned char byte[8] = {0}; // Unsigned char: somente 0 e positivos

	/* For que irá garantir a leitura e impressão de todos os 8 bytes */
	for (int i = 0; i < 8; i++){
		
		/* Cada byte será alocado em uma das 8 posições do vetor byte[8],
		sendo que char* apontará para o endereço de input nas posições */
		byte[i] = ((char*)(&input))[i];

		/* Impressão de cada byte com a máscara %x (hexadecimais) */
		printf("%x\n", byte[i]);

	}

	return 0;
}

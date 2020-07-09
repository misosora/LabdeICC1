/* Programa para realizar potências (com laço) */

#include <stdio.h> // Utilização das funções scanf() e printf()

int main(int argc, char *argv[]){
	
	/* Declaração das variáveis numero (a base) e resultado, ambas double para
	guardarem valores não-inteiros, e inicialização da variável numero */
	double numero = 0, resultado;

	/* Declaração e inicialização da variável expoente */
	int expoente = 0;

	/* Inicialização da variável resultado como 1, para que não haja
	multiplicação por zero no for */
	resultado = 1;
	
	scanf("%lf %d", &numero, &expoente);

	/* For que irá garantir a multiplicação de numero por numero n (expoente)
	vezes */
	for (int i = 0; i < expoente; i++){
		resultado *= numero; // A cada loop a variável resultado será atualizada
	}

	/* Impressão do resultado com 4 casa decimais */
	printf("%.4lf\n", resultado);
	
	return 0;
}

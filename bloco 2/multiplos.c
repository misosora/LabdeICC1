/* Programa para impressão de n múltiplos naturais de i e j */

#include <stdio.h> // Utilização das funções scanf() e printf()

int main(int argc, char *argv[]){
	
	/* Declaração e inicialização das variáveis n, que será a quantidade
	de múltiplos, i e j, que serão os números para análise */
	int n = 0, i = 0, j = 0;

	scanf("%d %d %d", &n, &i, &j);
	
	/* Declaração de uma variável auxiliar (contador) com o mesmo valor
	de n para garantir a impressão n vezes no for seguinte */
	int contador = n;

	/* For que irá verificar a multiplicidade dos números (k) por i e j */
	for (int k = 0; contador > 0; k++){
		
		/* Se o resto da divisão do número (k) por i ou j for 0, ele será
		impresso */
		if (k % i == 0 || k % j == 0){
			printf("%d\n", k);
			
			/* O contador será decrescido até chegar em 0 (posição de
			parada) */
			contador--;
		}
	}

	return 0;
}

/* Programa para calcular a média harmônica amortizada de N números */

#include <stdio.h> // Utilização das funções scanf() e printf()

int main(int argc, char *argv[]){
	
	/* Declaração e inicialização da variável N, que representa a
	quantidade de notas a serem utilizadas no cálculo da média */
	int N = 0;
	scanf("%d", &N);
	
	int i; // Declaração da variável auxiliar i
	
	/* Declaração do vetor notas[N], que guarda os valores inseridos
	pelo usuário */
	double notas[N];
	
	/* Declaração e inicialização das variáveis divisor, que receberá o 
	divisor da média, e media, que receberá o valor final da média */
	double divisor = 0, media = 0;
	
	/* For que irá registrar os valores inseridos de acordo com o valor N e 
	incrementar o divisor conforme a fórmula da média */
	for (i = 0; i < N; i++){
		notas[i] = 0; // Inicialização da variável notas[i]
		scanf("%lf", &notas[i]);

		divisor += (1.0/(notas[i] + 1.0));
	}
	
	/* Fórmula final da média harmônica amortizada, de acordo com o valor N 
	e com o divisor resultante do for */
	media = ((double) N / divisor) - 1.0; // Foi utilizado o (double) para
					      // permitir a operação

	/* Impressão da média final com duas casas decimais */
	printf("%.2lf\n", media);

	return 0;
}

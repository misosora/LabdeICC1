/* Programa para verificar o mês de maior acesso e sua média em servidores 
durante um ano */

#include <stdio.h> // Utilização das funções scanf() e printf()

int main(int argc, char *argv[]){
	
	/* Declaração e inicialização do vetor horas[12], que guardará os
	valores digitados pelo usuário */
	double horas[12] = {0};
	
	/* Declaração e inicialização das variáveis maior_media, que receberá 
	a maior média de acesso, e maior_mes, que será o mês correspondente */
	double maior_media = 0;
	int maior_mes = 0;

	int i; // Declaração da variável auxiliar

	/* For que irá ler e guardar os 12 valores digitados pelo usuário */
	for (i = 0; i < 12; i++){
		scanf("%lf", &horas[i]);
	}

	/* Assumimos que o maior valor é o primeiro para comparação */
	maior_media = horas[0];

	/* For que irá ler os 12 valores */
	for (i = 0; i < 12; i++){
		
		/* Se o próximo valor for maior que o anterior, as variáveis
		maior_media e maior_mes serão atualizadas */
		if (horas[i] > maior_media){
			maior_media = horas[i];
			maior_mes = i + 1;
		}
	}	
	
	/* Impressão do mês com maior média e da média correspondente */
	printf("%d %.2lf\n", maior_mes, maior_media);
	
	return 0;
}

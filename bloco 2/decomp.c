/* Programa para decompor um número inteiro em números primos */

#include <stdio.h> // Utilização das funções scanf() e printf()

int main(int argc, char *argv[]){
	
	// Declaração e inicialização da variável N, que receberá o inteiro a
	// ser fatorado (digitado pelo usuário)
	int N = 0;
	scanf("%d", &N);

	// For que irá começar com o primeiro valor primo (2) e garantir que
	// N é maior que 1
	for (int i = 2; N > 1; i++){
		
		// Declaração e inicialização da variável auxiliar aux
		int aux = 0;

		// While que irá rodar enquanto o resto da divisão de N por i
		// (primo) for zero
		while (N % i == 0){
			
			// O novo valor de N é sua divisão por i (primo) e a variável
			// aux é incrementada
			N /= i;
			aux++;
		}

		// Se a variável aux for diferente de 0, sabe-se que i é um primo
		// divisor de N
		if (aux != 0){
			
			// Impressão do número primo (i) e de sua incidência (aux)
			printf("%d %d\n", i, aux);
		}
	}
	return 0;
}

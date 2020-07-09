/* Programa para calcular a média harmônica amortizada de N números
utilizando múltiplas funções */

#include <stdio.h> // Utilização das funções scanf() e printf()

// Função que irá imprimir o valor final da média harmônica amortizada
double printDouble(double val){
	
	// Declaração e iniciliazação da variável resultado, que irá receber
	// o comando para impressão
	double resultado = 0;

	resultado = printf("%.2lf\n", val);

	return resultado;
}

// Função que irá ler e guardar os valores digitados pelo usuário (de acordo)
// com o valor de N) e realizar o cálculo da média
double readDouble(int N){
	
	// Declaração do vetor notas[N], o qual guardará os valores digitados
	// pelo usuário
	double notas[N];
	
	// Declaração e inicialização da variável divisor, a qual receberá o
	// divisor da média, e val, a qual receberá o valor final da média
	double divisor = 0, val = 0;

	// For que irá registrar os valores inseridos no vetor notas[N] e
	// incrementar o divisor conforma a fórmula da média
	for (int i = 0; i < N; i++){
		notas[i] = 0;
		scanf("%lf", &notas[i]);

		divisor += (1.0/(notas[i] + 1.0));
	}

	// Fórmula final da média, de acordo com o valor N e com o divisor
	// resultante do for
	val = ((double) N / divisor) - 1.0; // Casting para permitir a operação

	return val;
}

// Função que irá ler o inteiro digitado e guardá-lo
int readInt(){
	
	// Declaração e inicialização da variável N, que representa a quantidade
	// de notas a ser utilizada no cálculo da média
	int N = 0;
	scanf("%d", &N);

	return N;
}

// Função principal
int main(int argc, char *argv[]){
	int N = readInt(); // Lerá e guardará o primeiro inteiro digitado
	double val = readDouble(N); // Utilizará N para guardar os próximos
								// valores digitados e calculará a média
	printDouble(val); // Imprimirá a média
	
	return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);

	int num_atual = 0, encontrado = 0;
	for (int i = 0; num_atual < n; i++) {
		num_atual += i+1;
		if (num_atual == n) {
			printf("SIM\n");
			
			int num_prox = num_atual+i+2;
			printf("%d\n", num_prox);
			
			int soma = num_atual + num_prox;
			if (pow(sqrt(soma), 2) == soma) {
				printf("SIM\n");
			} else {
				printf("NAO\n");
			}
			
			encontrado = 1;
			break;
		}
	}

	if (encontrado == 0) {
		printf("NAO\n");
	}
	
	return 0;
}

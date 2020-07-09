#include <stdio.h>

int main() {

	int ano;

	scanf("%d", &ano);

	if (ano % 4 == 0)
		printf("SIM\n");
	else
		printf("NAO\n");
}

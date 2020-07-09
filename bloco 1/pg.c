#include <stdio.h>
#include <math.h>

int main(){
	float a,q,n,an,soma;

	scanf("%f %f %f", &a,&q,&n);
	
	an = a*(pow(q,n-1));
	printf("%.2f\n", an);

	soma = a*(pow(q,n)-1);
	printf("%.2f\n", soma/(q-1));
}

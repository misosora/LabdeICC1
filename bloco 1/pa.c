#include <stdio.h>
#include <math.h>

int main(){

	double a,r,n,an,soma;

	scanf("%lf", &a);
	scanf("%lf", &r);
	scanf("%lf", &n);

	an = a+(n-1)*r;
	printf("%.0lf\n", an);

	soma = ((a+an)*n)/2;
	printf("%.0lf\n", soma);
}

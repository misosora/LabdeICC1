#include <stdio.h>

int main(){
	double a,b,c,d,min,media;

	scanf("%lf %lf %lf %lf", &a,&b,&c,&d);
	min = a;
	if (min>b){
		min = b;
	}
	if (min>c){
		min = c;
	}
	if (min>d){
		min = d;
	}

	media = (a+b+c+d - min)/3;
	printf("%.4lf\n", media);
	
}

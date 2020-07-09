#include <stdio.h>

int main(){
	double a, b;
	char op;
	
	scanf("%lf %c %lf", &a, &op, &b);
	switch (op){
		case '+':
			printf("%lf\n", a+b);
			break;
		case '-':
			printf("%lf\n", a-b);
			break;
		case '*':
			printf("%lf\n", a*b);
			break;
		case '/':
			printf("%lf\n", a/b);
			break;
		case '%':
			printf("%lf", (a/b)*100);
			break;
	}
}

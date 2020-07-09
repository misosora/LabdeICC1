#include <stdio.h>
#include <math.h>

int main(){
	float a;
	scanf("%f", &a);
	printf("%.0f\n%.4f\n%.0f\n", floor(a),a-floor(a),round(a));
}

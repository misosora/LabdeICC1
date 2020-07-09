#include <stdio.h>
#include <math.h>

int main(){
	int N;
	double px, py, qx, qy, comprimento = 0;

	scanf("%d", &N);
	scanf("%lf %lf", &qx, &qy);

	for (int i = 0; i < N-1; i++){
		scanf("%lf %lf", &px, &py);

		comprimento = comprimento + sqrt(pow((qx-px), 2) + pow((qy-py), 2));
		qx = px;
		qy = py;
	}
	printf("%.4lf", comprimento);
}

#include <stdio.h>
#include <math.h>

int main(){
	int num_um, num_dois, num_tres;

	scanf("%d %d %d", &num_um, &num_dois, &num_tres);

	if (num_um == 0 || num_dois == 0 || num_tres == 0){
		printf("NAO");
	}
	else {
		if ((pow(num_um,2) + pow(num_dois,2)) == pow(num_tres,2)){
			printf("SIM");
		}
		else if ((pow(num_um,2) + pow(num_tres,2)) == pow(num_dois,2)){
			printf("SIM");
		}
		else if ((pow(num_dois,2) + pow(num_tres,2)) == pow(num_um,2)){
			printf("SIM");
		}
		else{
			printf("NAO");
		}
	}
}

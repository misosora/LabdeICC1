/*************************************************************************************************
(                _                USP-Universidade de São Paulo                 _                )
(    __   ___.--'_`.  ICMC-Instituto de Ciências Matemáticas e de Computação  .'_`--.___   __    )
(   ( _`.'. -   'o` ) ====================================================== ( 'o`   - .`.'_ )   )
(   _\.'_'      _.-'           Bacharelado em Ciências de Computação          `-._      `_`./_   )
(  ( \`. )    //\`                            2020/1                            '/\\    ( .'/ )  )
(   \_`-'`---'\\__, ========================================================== ,__//`---'`-'_/   )
(    \`        `-\           __    __                                           /-´        ´/    )
(     `                     ( 0)__( 0)  Gabriela Satie Faria Nishimi                       ´     )
(                           /   ''   \     ____________________                                  )
(                          ( ´´  3 ´´ )  < Número USP: 11892820)                                 )
(                           \        /                                                           )
(                           /___>o<__\                                                           )
(                           uuu    uuu                                                           )
( Programa: Busca Binária                                                                        )
*************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void readElements(int *elements, int size){
	for(int i = 0; i < size; i++){
		scanf("%d", &elements[i]);
	}
	
	return;
}

int comparator(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

void sortElements(int *elements, int size){
	qsort(elements, size, sizeof(int), comparator);

	return;
}

int binarySearch(int *elements, int key, int left, int right){
	while(left <= right){
		int middle = left + (right - left)/2;

		if(elements[middle] == key){
			return middle;
		}
		if(elements[middle] < key){
			left = middle + 1;
		}else{
			right = middle - 1;
		}
	}
	
	return -1;
}

int main(int argc, char *argv[]){
	int size, key;
	scanf("%d %d", &size, &key);

	int *elements = (int *) malloc(size*sizeof(int));

	readElements(elements, size);
	sortElements(elements, size);
	int result = binarySearch(elements, key, 0, size-1);

	if(result != -1){
		printf("%d\n", result);
	}else{
		printf("Chave inexistente\n");
	}

	free(elements);
	return 0;
}

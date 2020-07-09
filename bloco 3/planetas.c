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
( Programa: Horários Interplanetares                                                             )
*************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void operations(unsigned long long sec, char *planet){
	unsigned long long days, hours, minutes, seconds;
	
	if(strcmp(planet, "Terra") == 0){
		days = sec/86400;
		sec -= 86400*days;
		
		hours = sec/3600;
		sec -= 3600*hours;
		
		minutes = sec/60;
		sec -= 60*minutes;

		seconds = sec;

		printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n", days, hours, minutes, seconds);
	}

	if(strcmp(planet, "Venus") == 0){
		days = sec/20995200;
		sec -= 20995200*days;

		hours = sec/3600;
		sec -= 3600*hours;
	
		minutes = sec/60;
		sec -= 60*minutes;

		seconds = sec;

		printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n", days, hours, minutes, seconds);
	}

	if(strcmp(planet, "Mercurio") == 0){
		days = sec/5068800;
		sec -= 5068800*days;

		hours = sec/3600;
		sec -= 3600*hours;

		minutes = sec/60;
		sec -= 60*minutes;

		seconds = sec;
	
		printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n", days, hours, minutes, seconds);
	}
	
	if(strcmp(planet, "Jupiter") == 0){
		days = sec/35760;
		sec -= 35760*days;

		hours = sec/3600;
		sec -= 3600*hours;

		minutes = sec/60;
		sec -= 60*minutes;

		seconds = sec;
	
		printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n", days, hours, minutes, seconds);
	}

	return;
}

int main(int argc, char *argv[]){
	unsigned long long sec;
	char *planet = (char *) malloc(10*sizeof(char));
	scanf("%llu %s", &sec, planet);

	printf("%llu segundos no planeta %s equivalem a:\n", sec, planet);
	
	operations(sec, planet);

	free(planet);
	return 0;
}

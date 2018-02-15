#include <stdio.h>
#include <stdlib.h>

int main(void){
    double lower = 0;
    double upper = 300;
    double step = 20;

    double fahr;
    double celsius = lower;

    printf("fahr  cel\n");
    printf("==========\n");

    while (celsius <= upper){
	fahr = ((9.0/5.0) * celsius) + 32;
	printf("%3.0f %6.1f\n", celsius, fahr);
	celsius = celsius + step;
    }
    return(EXIT_SUCCESS);
}

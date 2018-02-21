#include <stdio.h>

double fahr_to_celsius(double fahr);

int main(void){
    double lower = 0, upper = 300, step = 20;

    for(double fahr = lower; fahr <= upper; fahr += step)
	printf("%3.0f\t%3.0f\n", fahr, fahr_to_celsius(fahr));

    return 0;
}

double fahr_to_celsius(double fahr){
    return 5 * (fahr - 32.0) / 9;
}

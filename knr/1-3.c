#include <stdio.h>

int main(void){
    // the original program in k&r makes fahr and celsius floats
    // but that produces warnings for implicit conversion
    double fahr, celsius;
    int lower, upper, step;

    lower = 0;   
    upper = 300; 
    step = 20;   
    
    printf("fahr  cel\n");
    printf("==========\n");
    fahr = lower;
    while (fahr <= upper){
	celsius = (5.0/9.0) * (fahr-32.0);
	printf("%3.0f %6.1f\n", fahr, celsius);
	fahr = fahr + step;
    }
    return(0);
}

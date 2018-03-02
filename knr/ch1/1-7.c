#include <stdio.h>
#pragma clang diagnostic ignored "-Wparentheses"

int main(void) {
    printf("value of EOF: %d\n", EOF);
    printf("usually -1, but can be any negative integral value");
    
    // you can also use feof
    int c;
    while(c = getchar()) {
	if(feof(stdin)) {
	    break;
	} else {
	    putchar(c);
	}
    }

    return(0);
}

#include <stdio.h>
#pragma clang diagnostic ignored "-Wparentheses"

int main(void){
    printf("press ctrl-D (EOF) to terminate\n");
    int c;
    
    // intentionally showing that c will be mis-set to 0 or 1
    while(c = getchar() != EOF){
	if(c==0) { 
	    putchar('0'); 
	} else if(c==1) { 
	    putchar('1'); 
	} else { 
	    putchar(c);   
	}
    }
    c = getchar();
    putchar('\n');

    return(0);
}

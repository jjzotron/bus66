#pragma clang diagnostic ignored "-Wunused-comparison"
#include <stdio.h>

/* this exercise was just converting 
 * some for loop to a while loop */

int main(void){
    int i=0;
    int c = 0;
    int lim = 0;
    int s[10];
    
    while((c = getchar())){
	if(c == EOF)
	    break;
	if(c == '\n')
	    break;
	if(i >= lim-1)
	    break;
	
	s[i] == c;
	i++;
    }
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>


int main(void){
    int current_char, last_char, putchar_ret;
    last_char = (int)'a'; // set to any character except space
    
    while((current_char = getchar()) != EOF){
	if(current_char != (int)' ' || last_char != (int)' '){
	    putchar_ret = putchar(current_char);
	    if (putchar_ret == EOF){
		perror("1-9 error:");
		return(EXIT_FAILURE);
	    }
	} 
	last_char = current_char;
    }
    return(0);
}

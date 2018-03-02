#include <stdio.h>

#define IN  1
#define OUT 0

int main(void){
    int current_char;
    int state = OUT;

    while ((current_char = getchar()) != EOF){
	if(current_char == '\n' || current_char == ' ' || current_char == '\t'){
	    if(state == IN){
		printf("\n");
	    }
	    state = OUT;
	} else {
	    if(state == OUT){
		state = IN;
	    }
	    printf("%c", current_char);
	}
	/*
	  state current_char task
	    1     w        -> set state to out
	    1     n        -> print char
	    0     w        -> ignore it
	    0     n        -> print newline, set state to in
	*/
    }
    return(0);
}

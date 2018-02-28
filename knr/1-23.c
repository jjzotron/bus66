#include <stdio.h>
#include <stdbool.h>

int main(void){
    int curr_char;
    int lookahead_char = getchar(); // need lookahead to avoid printing the slashes
    bool inside_string = lookahead_char == '\"'; 
    
    while((curr_char = lookahead_char) != EOF){
	lookahead_char = getchar();
	
	if(curr_char == '\"'){
	    if (inside_string)
		inside_string = false;
	    else
		inside_string = true;
	} else if(!inside_string && curr_char == '/' && lookahead_char == '/'){
	    // ignore rest of line
	    while((lookahead_char = getchar()) != EOF)
		if(lookahead_char == '\n')
		    break;
	} else if(!inside_string && curr_char == '*' && lookahead_char == '/'){
	    // handle multi-line comment
	    printf("/* handle comment here */");
	} else {
	    putchar(curr_char);
	}
    }
    return 0;
}

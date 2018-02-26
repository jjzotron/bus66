#include <stdio.h>
#define SPACES_PER_TAB 8

int main(void){
    int curr_char;
    int line_position = 0;
    int spaces = 0;
    int tabs = 0;

    while((curr_char = getchar()) != EOF){
	// if you hit a space, count tabs/spaces to print
	if (curr_char == ' ') {
	    if((line_position % SPACES_PER_TAB) != 0){
		spaces++;
	    } else{ 
		spaces = 0;
		tabs++;
	    }
	} else { // if not a space, write characters
	    while(tabs > 0) {
		putchar('\t'); tabs--;
	    }
	    
	    if (curr_char != '\t') {
		while(spaces > 0){ putchar(' '); spaces--; }
	    } else {
		spaces = 0;
	    }

	    putchar(curr_char);
	    
	    if(curr_char == '\n')
		line_position = 0;
	    else if (curr_char == '\t')
		line_position = line_position + (SPACES_PER_TAB - line_position % SPACES_PER_TAB);
	}
    }
    return 0;
}

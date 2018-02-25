#include <stdio.h>
#define SPACES_PER_TAB 8

/* replaces tabs with spaces */
int main(void){
    int curr_char;
    int line_position = 0;
    int spaces_until_tabstop = 0;
    
    while((curr_char = getchar()) != EOF){
	if (curr_char == '\n') { line_position = 0; }
	
	if (curr_char != '\t') {
	    putchar(curr_char);
	    line_position++;
	} else {
	    spaces_until_tabstop = SPACES_PER_TAB - (line_position % SPACES_PER_TAB);
	    
	    for(int i=0; i<spaces_until_tabstop; i++, line_position++)
		putchar(' ');
	}
    }
    return 0;
}

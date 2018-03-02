#include <stdio.h>

/* need a term with ansi colors */
#define COLOR_GREEN "\x1B[32m"
#define COLOR_WHITE "\x1B[37m"
#define RESET_COLORS "\033[0m"

int main(void){
    int current_char;
    while((current_char = getchar()) != EOF){
	if(current_char == (int)'\t')
	    printf("%s\\t", COLOR_GREEN);
	else if(current_char == (int)'\n')
	    printf("%s\\n\n", COLOR_GREEN);// note this also actually prints newline
	else if(current_char == (int)'\b')
	    printf("%s\\b", COLOR_GREEN);
	else if(current_char == (int)'\\')
	    printf("%s\\\\", COLOR_GREEN);
	else 
	    printf("%s%c", COLOR_WHITE, current_char);
	
	// this has to be in the loop because a line might end on a color
	printf("%s", RESET_COLORS); 
    }
    printf("\n");
    return(0);
}

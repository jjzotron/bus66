#include <stdio.h>
#include <ctype.h>

int main(void){
    int char_counts[256] = {0};
    int curr_char;
    
    while ((curr_char = getchar()) != EOF){
	char_counts[curr_char]++; // this can overflow int
    }

    for(int i=0; i<256; i++){
	if(!isalnum(i)) continue;
	if(char_counts[i] < 1) continue;
	
	printf("%c: ", i);
	for(int j=0; j<60 && j<char_counts[i]; j++){ // chose 60 just to fit terminal width
	    putchar('#');
	}
	printf("\n");
    }

    return 0;
}

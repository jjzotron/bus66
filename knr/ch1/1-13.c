#include <stdio.h>

#define HISTOGRAM_MAX_LENGTH 10
#define IN 1
#define OUT 0


int main(void){
    int current_char;
    int current_word_length = 0;
    int state = OUT;
    int word_lengths[HISTOGRAM_MAX_LENGTH+1] = {0};// ignore the 0 len words

    while((current_char = getchar()) != EOF){
	if(current_char == '\n' || current_char == ' ' || current_char == '\t'){
	    if(state == IN){
		// end of word reached, record word len
		if(current_word_length >= HISTOGRAM_MAX_LENGTH){
		    word_lengths[HISTOGRAM_MAX_LENGTH]++;
		} else {
		    word_lengths[current_word_length]++;
		}
	    }
	    state = OUT;
	    current_word_length = 0;
	} else {
	    if(state == OUT){
		// just started a new word
		state = IN;
	    }
	    current_word_length++;
	}
    }

    for(int i=1; i<=HISTOGRAM_MAX_LENGTH; i++){
	if(i == HISTOGRAM_MAX_LENGTH){
	    printf("%3d+: ", i);
	} else {
	    printf("%3d : ", i);
	}
	for(int j = 0; j<word_lengths[i] && j<80; j++){ // term width 80?
	    putchar('#');
	}
	printf("\n");
    }

    return(0);
}

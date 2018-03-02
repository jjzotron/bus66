#include <stdio.h>

int main(int argc, char *argv[]){
    // uninitialized
    FILE *fp;
    int current_char;

    // initialized
    int number_of_tabs     = 0;
    int number_of_spaces   = 0;
    int number_of_newlines = 0;


    if(argc == 1){
	fp = stdin;
	printf("type some stuff, then ctrl-D (or EOF)\n");
    } else if (argc == 2){
	fp = fopen(argv[1], "r");
	if(fp == NULL){
	    printf("tried to open file: %s\n", argv[1]);
	    perror("1-8.out error:");
	    return(-1);
	}
    } else {
	printf("usage: ./1-8.out [file]\n");
	return(0);
    }

    while ((current_char = fgetc(fp)) != EOF){
	if(current_char == (int)'\t'){
	    number_of_tabs++;
	} else if(current_char == (int)' '){
	    number_of_spaces++;
	} else if(current_char == (int)'\n'){
	    number_of_newlines++;
	}
    }

    printf("tabs:%d, spaces:%d, newlines:%d\n", number_of_tabs, number_of_spaces, number_of_newlines);
    
    fclose(fp);
    return(0);
}

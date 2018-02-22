#include <stdio.h>
#define MAXLINE 1000

int knr_getline(char s[], int lim);

int main(void){
    char line[MAXLINE] = {0};
    int line_len;
    
    while((line_len = knr_getline(line, MAXLINE)) > 0){
	if(line_len > 80)
	    printf("%s\n", line);
    }
    return 0;
}

/* read a line into s, return length */
int knr_getline(char s[], int lim){
    int c = EOF;
    int i;
    
    for(i=0; i<lim-1 && ((c = getchar()) != EOF) && c!= '\n'; i++)
	s[i] = (char)c;

    if(c=='\n'){
	s[i] = (char)c;
	i++;
    }
    
    s[i] = '\0';
    return i;
}

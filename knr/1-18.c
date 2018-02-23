#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

int knr_getline(char s[], int lim);
int last_whitespace(char s[], int len);

int main(void){
    char line[MAXLINE] = {0};
    int line_len;

    while((line_len = knr_getline(line, MAXLINE)) > 0){
	int lw = last_whitespace(line, line_len);

	if(line[line_len -1] == '\n'){
	    line[lw] = '\n';
	    line[lw+1] = '\0';
	} else {
	    line[lw] = '\0';
	}

	printf("%s", line);
    }
    
    return 0;
}

int last_whitespace(char s[], int len){
    int last_whitespace = len;
    for(int i=len-1; i>=0; i--){
	if (isspace(s[i]))
	    last_whitespace = i;
	else
	    break;
    }
    return last_whitespace;
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

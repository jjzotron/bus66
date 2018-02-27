#include <stdio.h>
#include <ctype.h>
#define MAXLINE 80

static int knr_getline(char s[], int lim);
static int last_whitespace(char s[], int len);

/* splits text lines longer than 80, does not handle tab-stops */
int main(void){
    int len = 0;
    char line[MAXLINE]; // not a nul terminated string

    while((len += knr_getline(line, MAXLINE-len)) != 0){
	if(line[len-1] == '\n'){
	    for(int i=0; i<len; i++) putchar(line[i]);
	    len = 0;
	} else {
	    int last_ws = last_whitespace(line, len);
	    for(int i=0; i<last_ws; i++)
		putchar(line[i]);
	    
	    putchar('\n');
	    len -= last_ws; // start next getline from where line was split
	}
    }

    return 0;
}

/* returns index of last whitespace or -1 */
static int last_whitespace(char s[], int len){
    while(isspace(s[len-1]) && len >= 0) len--;
    return len;
}

/* read a line into s, return length */ 
static int knr_getline(char s[], int lim){
    int c = EOF;
    int i;
    
    for(i=0; i<lim-1 && ((c = getchar()) != EOF) && c!= (int)'\n'; i++)
	s[i] = (char)c;

    if(c==(int)'\n'){
	s[i] = (char)c;
	i++;
    }
    
    s[i] = '\0';
    return i;
}


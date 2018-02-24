#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

static void reverse(char s[], unsigned long len);
static int knr_getline(char s[], int lim);

int main(void){
    char line[MAXLINE];
    int len;
    
    while((len = knr_getline(line, MAXLINE)) != 0){
	// preserve newline (which can only happen as last char in knr_getline
	if(line[len-1] == '\n')
	    len--;
	
	reverse(line, (unsigned long)len);
	printf("%s", line);
    }

    return 0;
}

static void reverse(char s[], unsigned long len){
    unsigned long last, i;
    char tmp;
    
    if(len <= 1) return; // nothing to reverse
    last = len - 1; 
    
    for(i=0; i < last; i++, last--){
	tmp = s[i];
	s[i] = s[last];
	s[last] = tmp;
    }
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


#include <stdio.h>
#define MAXLINE 10

static void copy(char to[], char from[]);
static int knr_getline(char s[], int lim);

/* this exercise says to modify the main routine
 * im not sure whether that means to only modify main(),
 * but it can be done. it makes more sense to modify getline()
 */

int main(void){
    int len = tmp = 0; // current line len, sum of current line len
    int max = 0; // best line length so far
    char line[MAXLINE] = ""; // current line
    char longest[MAXLINE] = ""; // longest saved line

    while((len = knr_getline(line, MAXLINE)) > 0){
	// if it was a full line and the line didn't end yet
	if((len == MAXLINE-1) && (line[MAXLINE-2] != '\n')){
	    tmp += len;
	    len = 0;
	} else if(len>max){
	    max = len + tmp;
	    tmp = len = 0;
	    copy(longest, line);
	} 
    }
    if(max > 0)
	printf("\nlongest (%d) ends with:\n%s", max, longest);
    
    return 0;
}

/* read a line into s, return length */
static int knr_getline(char s[], int lim){
    int c, i;
    for(i=0; i<lim-1 && (c = getchar())!=EOF && c!='\n'; ++i){
	s[i] = c;
    }
    if (c == '\n'){
	s[i] = c;
	++i;
    }
    s[i] = '\0';
    return i;
}

/* copy 'from' into 'to'; assume to is big enough*/
static void copy(char to[], char from[]){
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
	++i;
}

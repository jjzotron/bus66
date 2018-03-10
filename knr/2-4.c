#include <stdio.h>
#include <string.h>

static void squeeze(char s[], int c);
static void multi_squeeze(char s[], char t[]);

int main(void){
    char my_str1[] = "abcdef";
    char my_str2[] = "efghi";

    squeeze(my_str1, 'c');
    multi_squeeze(my_str1, my_str2);
    
    printf("%s\n", my_str1);
    return 0;
}

static void multi_squeeze(char s[], char t[]){
    for(int i=0; t[i] != '\0'; i++)
	for(int j=0; s[j] != '\0'; j++)
	    if(t[i] == s[j])
		squeeze(s, t[i]);
}

static void squeeze(char s[], int c){
    int i, j;

    for(i=j=0; s[i] != '\0'; i++)
	if(s[i] != c)
	    s[j++] = s[i];
    s[j] = '\0';
}

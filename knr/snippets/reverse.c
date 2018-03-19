# include <string.h>

/* reverse string s in place, from k&r */
void reverse(char s[]){
    int c, i, j;

    for(i=0; (void)(j=(int)strlen(s)-1), i<j; i++, j--){
	c = (int)s[i];
	s[i] = s[j];
	s[j] = (char)c;
    }
}


char *strrev(char *str) {
    unsigned long i = strlen(str) - 1;
    unsigned long j = 0;
    char c;
    
    while (i > j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i--;
        j++;
    }
    
    return str;
}

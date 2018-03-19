#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);
char *strrev(char *s);

int main(void){
    int n = INT_MIN;
    char s[100] = "";

    itoa(n, s);
    printf("%s\n", s);
    return 0;
}

void itoa(int _n, char s[]){
    long i, sign, n;
    n = (long)_n; // to make it work with INT_MIN
    // could also use abs() in 
    
    if((sign = n) < 0)
       n = -n;
    i = 0;
    do {
	s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
	s[i++] = '-';
    s[i] = '\0';
    s = strrev(s);
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

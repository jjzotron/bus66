#include <stdio.h>

static char lower(char c);

int main(void){
    char a = 'A';
    char b = 'B';
    
    printf("lower(): A -> %c, B -> %c\n", lower(a), lower(b));
    return 0;
}

static char lower(char c){
    c = (c <= 'Z' && c >= 'A') ? c + ('a' - 'A') : c;
    return c;
}

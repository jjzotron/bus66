#include <stdio.h>
#include <unistd.h>
#pragma clang diagnostic ignored "-Wunknown-escape-sequence"

int main(void){
    printf("escape characters in printf():\n");
    
    // testing an invalid escape character:
    printf("(\\q): \q\n");
    // produces error with -Werror
    // warns and prints the character without
    // but this is undefined behavior

    // can't find escape characters in "man 3 printf" so I tried some shell ones
    // escape codes: a, b, c, f, n, r, t, v, \, and a number
    printf("(\\a)\a"); // makes a bell sound
    printf("\n");

    //printf("(123\\c123):123\c123"); // ignore rest of characters, unrecognized
    //printf("\n");

    printf("abc\rcde (abc\\rcde)"); // return
    printf("\n");

    printf("(\\v):\v"); // vertical tab
    printf("\n");

    printf("(\\123):\123"); // octal
    printf("\n");

    // using backspace
    for(int i=0; i<4; i++){
	printf("abc");
	sleep(1);
	printf("\b"); 
	fflush(stdout);
    }
    printf("\n");

    return(0);
}

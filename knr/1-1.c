#include <stdio.h>
#include <limits.h>

void test();

int main(void){
    test(); // check compiler warns
    printf("Hello World\n");
}

void test() {
    //int x;
    int x=INT_MAX;
    int y = x + 1; // warn: left operand is garbage
    y--; 
}


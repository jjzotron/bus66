#include <stdio.h>
#include <limits.h>
#pragma clang diagnostic ignored "-Wunused-variable"

static void test() {
    //int x;
    int x=INT_MAX;
    int y = x + 1; // warn: left operand is garbage
}


int main(void){
    test(); // check compiler warns
    printf("Hello World\n");
    return(0);
}


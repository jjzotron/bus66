#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void){
    unsigned x = 0x1;
    unsigned y = 0x6;

    x = setbits(x, 3, 2, y); 
    return 0;
}

/* set n bits of x at position p, coping from y 
 * position p=0 is at the right end */
unsigned setbits(unsigned x, int p, int n, unsigned y){
    // get a bitmask for n positions starting at x
    unsigned mask = ~(~(~0u << n) << (p+1-n));
    // set the x bits to zero
    unsigned x_val = x & mask;
    // set the rightmost n bits of y
    unsigned y_val = (y & ~(~0u << n)) << (p+1-n);
    return x_val | y_val;
}

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void){
    unsigned x = 0x6;
    unsigned x2 = invert(x, 4, 4); // flip last 4 bits
    printf("before:%x, after:%x\n", x, x2);
    return 0;
}

/* invert n bits beginning at p in x */
unsigned invert(unsigned x, int p, int n){
    printf("x: %x\n", x);
    // get a bitmask for n positions starting at x
    unsigned mask = ~(~(~0u << n) << (p-n));
    // set those bits to 0
    unsigned x_val = x & mask;
    // or the cleared word with the flipped bits
    unsigned flipped = x_val | (~x & ~mask);
    return flipped;
}

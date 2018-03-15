#include <stdio.h>

// count the number of 1-bits in x
static int bitcount(unsigned x);
static int bitcount2(unsigned x);

int main(void){
    // assumes 2s comp, 4+ byte ints
    unsigned x = 0xF0F0; // should have 8 zeros
    printf(" bitcount(%x): %d\n", x, bitcount(x));
    printf("bitcount2(%x): %d\n", x, bitcount2(x));
    return 0;
}

static int bitcount(unsigned x){
    // arg is unsigned to make sure zero filled when shifted
    int b;
    for(b = 0; x != 0; x >>= 1){
	if(x & 01){
	    b++;
	}
    }
    return b;
}

static int bitcount2(unsigned x){
    // x = &= (x-1) deletes the rightmost bit
    int count = 0;
    while(x != 0){
	count++;
	x &= (x - 1);
    }
    return count; 
}

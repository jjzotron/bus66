#include <stdio.h>
#include <limits.h>

/* rotate x to the right by n positions */
static unsigned rightrot(unsigned x, int n);
static unsigned alternate(unsigned x, int n);

int main(void){
    unsigned x = 0x00FF;
    unsigned y = rightrot(x, 7);
    unsigned z = alternate(x, 7);
    
    printf("before: %x\nafter: %x\n(alternate: %x)\n", x, y, z);
    return 0;
}

static unsigned rightrot(unsigned x, int n){
    unsigned leftbit = (unsigned)INT_MIN;
    int set_leftbit_p = 0;
    
    while(n > 0){
	set_leftbit_p = x & 1;
	x = x >> 1;
	if(set_leftbit_p){
	    //printf("x\n");
	    x = x | leftbit;
	}
	n--;
    }
    return x;
}

static unsigned alternate(unsigned x, int n){
    unsigned wordlength, right_bit;
    int i;
    unsigned v;
    
    // calculate word length
    v = (unsigned) ~0;
    for(i=1; (v =  v >> 1) > 0; i++)
	;
    wordlength = (unsigned) i;

    // rotate the word
    while(n-- > 0){
	right_bit = (x & 1) << (wordlength - 1);
	x = x >> 1;
	x = x | right_bit;
    }
    
    return x;
}

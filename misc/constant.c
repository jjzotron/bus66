#include <stdio.h>

int main(void){
    // negative unsigned constant
    // does not warn (-Weverything)
    unsigned long num = -1UL; // -> some big number
    // unsigned long x = (unsigned long) -1; -> but no warning here either

    // constant too large for container
    // gives warning with -Wconstant-conversion
    char num2 = 1000; // -> -24

    // assign an int slightly too high for float (assumed equal sizes)
    // does not warn
    // 16777217 = (2^24) + 1; 24 is # of mantissa bits
    float num3 = 16777217; // -> 16777216

    return 0;
}

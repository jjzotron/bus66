#include <stdio.h>
#include <limits.h>

/* print ranges of char, short, int, long. (signed and unsigned) */
int main(void){
    // assuming 2's comp on the signed values
    // endianness? shifting ub?
    // unsigned min values are all zero
    
    unsigned char max_uc = (unsigned char)~0;
    char min_c = ~0 >> 1; 
    char max_c = ~min_c;
    
    unsigned short max_us = (unsigned short)~0;
    short min_s = ~0 >> 1;
    short max_s = ~min_s;
    
    unsigned int max_ui = (unsigned int)~0;
    int min_i = ~0 >> 1;
    int max_i = ~min_i;
    
    unsigned long max_ul = (unsigned long)~0;
    long min_l = ~0 >> 1;
    long max_l = ~min_l;

    printf("Calculated values:\n");
    printf( "char:  umax:%-20d smin:%-20d smax:%-20d\n", max_uc, min_c, max_c);
    printf( "short: umax:%-20d smin:%-20d smax:%-20d\n", max_us, min_s, max_s);
    printf( "int:   umax:%-20d smin:%-20d smax:%-20d\n", max_ui, min_i, max_i);
    printf("long:  umax:%-20lu smin:%-20ld smax:%-20ld\n", max_ul, min_l, max_l);

    // print if there is a difference between calculated min/max and header macros
    /*
    printf("\n");
    if(max_uc != UCHAR_MAX || min_c != SCHAR_MIN || max_c != SCHAR_MAX)
	printf("CHAR MISMATCH (%d)\n");
    if(max_us != USHRT_MAX || min_s != SHRT_MIN || max_s != SHRT_MAX)
	printf("SHORT INT MISMATCH (%d)\n");
    if(max_ui != UINT_MAX || min_i != INT_MIN || max_i != INT_MAX)
	printf("INT MISMATCH (%d)\n");
    if(max_ul != ULONG_MAX || min_l != LONG_MIN || max_l != LONG_MAX)
	printf("LONG MISMATCH (%ld)\n");
    */
    
    return 0;
}

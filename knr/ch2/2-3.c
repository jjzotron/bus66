#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>

int htoi(char s[], int len);

int main(void){
    char hex_val[] = "FC";
    assert(strlen(hex_val) <= INT_MAX);
    int len = (int) strlen(hex_val);

    int result = htoi(hex_val, len);
    printf("input: %s, result: %d\n", hex_val, result);
    return 0;		
}

int htoi(char s[], int len){
    if(len == 0)
	return -1;
    
    // what if there was the empty string 
    // chop off the 0X
    int total = 0;
    
    for(int i=0; i<len; i++){
	if(isdigit(s[i])){
	    total = 16 * total + s[i] - '0';
	} else if(s[i] >= 'A' && s[i] <= 'F'){
	    int num = 16 * total + (s[i] - 'A' + 10);
	    total = num;
	} else if(s[i] >= 'a' && s[i] <= 'f'){
	    int num = 16 * total + (s[i] - 'a' + 10);
	    total = num;
	} else {
	    return -1;
	}
    }

    //printf("htoi(): %s", s);
    return total;
}

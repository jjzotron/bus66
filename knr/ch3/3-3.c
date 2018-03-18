#include <stdio.h>
#include <ctype.h>
#include <string.h>

static void expand(char s1[], char s2[]);

int main(void){
    char a[] = "1-6";
    char buff[1000] = "";

    expand(a, buff);
    printf("%s\n", buff);
    return 0;
}

/* expands shorthand
 * a-z -> abc...xyz CHECK
 * a-b-c -> abc CHECK
 * a-z0-9 -> abc..xyz012..789
 * leading or trailing '-' are taken literally */
static void expand(char s1[], char s2[]){
    int j = 0; // index for writing in s2
    int s1_len = (int)strlen(s1);

    for(int i=0; s1[i] != '\0'; i++){
	if(s1[i] == '-'){
	    if ((isdigit(s1[i-1]) && !isdigit(s1[i+1])) // both are not digits
		|| (isalpha(s1[i-1]) && !isalpha(s1[i+1])) // or both not alphabetic
		|| i == 0 // stop OOB from accessing before first element
		|| i == s1_len-1){ // stop OOB from accessing after last elem
		s2[j++] = '-';
		continue;
	    }
		
	    // +1/-1 to disclude start and end characters
	    // start/end are printed in else
	    // this only prints characters between the start and end
	    char start = s1[i-1] + 1; 
	    char end = s1[i+1] - 1;
	    while (start <= end){
		s2[j++] = start;
		start++;
	    }
	} else {
	    s2[j++] = s1[i];
	}
    }
    return;
}

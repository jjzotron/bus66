#include <stdio.h>

int any(char a[], char b[]);

int main(void){
    char my_str[] = "testing 123";
    char my_str2[] = "ghi";
    
    int index = any(my_str, my_str2);
    printf("%d\n", index);
    return 0;
}

/* return first index in a[] of shared character */
int any(char a[], char b[]){
    for(int i=0; a[i] != '\0'; i++)
	for(int j=0; b[j] != '\0'; j++)
	    if (a[i] == b[j])
		return i;
    return -1;
}

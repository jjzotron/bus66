#include <stdio.h>
#include <string.h>

static void escape(char s[], char t[]);
static void unescape(char s[], char t[]);

int main(void){
    char str[] = "abcd\\efg\thij";
    char str2[100];
    char str3[100];

    escape(str, str2);
    unescape(str2, str3);
    
    printf(" before: %s\n", str);
    printf("  after: %s\n", str2);
    printf("restore: %s\n", str3);
    return 0;
}

/* copy s to t, making some escaped characters visible */
static void escape(char s[], char t[]){
    int i = 0;
    int j = 0;
    
    while(s[i] != '\0'){
	switch(s[i]){
	case '\\':
	    t[j++] = '\\';
	    t[j++] = '\\';
	    break;
	case '\n':
	    t[j++] = '\\';
	    t[j++] = 'n';
	    break;
	case '\t':
	    t[j++] = '\\';
	    t[j++] = 't';
	    break;
	default:
	    t[j++] = s[i];
	    break;
	}
	
	i++;
    }
    t[j] = '\0'; // add the newline back
}

static void unescape(char s[], char t[]){
    int i = 0;
    int j = 0;

    while(s[i] != '\0'){
	// todo: tidy this bit
	if (s[i] != '\\'){
	    t[j] = s[i];
	    i++;
	    j++;
	    continue;
	}
	
	i++; // s[i] is a backslash, skip it
	switch (s[i]){
	case 't':
	    t[j] = '\t';
	    break;
	case '\\':
	    t[j] = '\\';
	    break;
	case 'n':
	    t[j] = '\n';
	    break;
	default:
	    t[j] = '?';
	    break;
	}
	i++;
	j++;
    }
    t[j] = '\0'; // restore newline
}

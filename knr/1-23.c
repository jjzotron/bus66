#include <stdio.h>
#include <stdbool.h>

int main(void){
    int curr_char;
    int lookahead_char = getchar(); // need lookahead to avoid printing the slashes
    
    while((curr_char = lookahead_char) != EOF){
	lookahead_char = getchar();
	
	if(curr_char == '\"'){
	    putchar(curr_char);
	    putchar(lookahead_char);
	    curr_char = lookahead_char;
	    
	    while((lookahead_char = getchar()) != EOF){
		putchar(lookahead_char);
		if(lookahead_char == '\"' && curr_char != '\\') // an unescaped quote
		    break;
		curr_char = lookahead_char;
	    }
	    lookahead_char = getchar(); // don't cycle in a quote loop
	} else if(curr_char == '/' && lookahead_char == '/'){
	    while((lookahead_char = getchar()) != EOF)
		if(lookahead_char == '\n')
		    break;
	} else if(curr_char == '/' && lookahead_char == '*'){ 
	    curr_char = 0;
	    while((lookahead_char = getchar()) != EOF){
		if(curr_char == '*' && lookahead_char == '/')
		    break;
		curr_char = lookahead_char;
	    }
	    lookahead_char = getchar();
	} else {
	    putchar(curr_char);
	}
    }
    return 0;
}


/* the lookahead thing is kinda hard to follow. I think it should
 only recur on the current character. if it starts as a " or /, then 
get more characters as necessary. 

e.g.:
while((curr_char = getchar() != EOF))
if(curr_char == '\"')
-> handle quote
else if(curr_char == "/")
tmp = getchar()
if(tmp == '/' || tmp == '*')
-> handle comments

also, I didn't see what happens in subsequent calls to
 getchar() after EOF, it seems a bit kludgey
*/

/* some test cases to try are: comments in quotes, comments in comments, quotes in quotes, quotes in comments */


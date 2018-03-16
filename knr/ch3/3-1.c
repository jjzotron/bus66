#include <stdio.h>

// assumes v is sorted, returns position of x in v[] or -1
int binsearch(int x, int v[], int len);
int binsearch2(int x, int v[], int len);

int main(void){
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    printf("binsearch(1-15): %d\n", binsearch2(5, numbers, 15));
    return 0;
}

int binsearch(int x, int v[], int len){
    int low, high, mid;
    
    low = 0;
    high = len-1;
    while(low <= high){
	mid = (low + high) / 2; // this can integer overflow
	if (x < v[mid])
	    high = mid - 1;
	else if (x > v[mid])
	    low = mid + 1;
	else
	    return mid;
    }
    return -1;
}

int binsearch2(int x, int v[], int len){
    int low, high, mid;
    
    low = 0;
    high = len-1;
    mid = (low + high) / 2;
    while(low <= high && x != v[mid]){
	if (x < v[mid])
	    high = mid - 1;
	else
	    low = mid + 1;
	mid = (low + high) / 2; // this can overflow
    }
    if(x == v[mid]) return mid;
    return -1;
}

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    int k;     
    scanf("%d %d",&n,&k);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    
    /* Allocate a new array to hold the new shifted value */    
    int *b = malloc(sizeof(int) * n);
    
    /*
     * copy over the existing array contents to new array:
     * from kth position of existing to the new array's 0th index
     * This can be acheived by modulo of the array index as below
     */
    for(int a_i=k, b_i=0; b_i < n; a_i++, b_i++)
    {
        b[b_i] = a[a_i%n];
    }
    
    /* Just print it */
    for(int b_i=0; b_i < n;b_i++)
    {
        printf("%d ", b[b_i]);        
    }    
    
    return 0;
}

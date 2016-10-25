#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void rotate_right_array(int * a, int n, int k)
{
    int temp, k_i;
    
    for (k_i = 0; k_i < k; k_i++)
    {
        temp = a[n-1];
        memmove(&a[1], &a[0], (n-1) * sizeof(int));
        a[0] = temp;
    }
    
    return;    
}

int main()
{
    int n; 
    int k; 
    int q; 
    scanf("%d %d %d",&n,&k,&q);
    int *a = malloc(sizeof(int) * n);
    int *mi = malloc(sizeof(int) * q);
    
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    
    for(int a0 = 0; a0 < q; a0++){
        scanf("%d",&mi[a0]);
    }
    
    rotate_right_array(a, n, k);
    
    for (int q0; q0 < q; q0++)
    {
        printf("%d\n", a[ mi[q0] ]);        
    }
    
    return 0;
}

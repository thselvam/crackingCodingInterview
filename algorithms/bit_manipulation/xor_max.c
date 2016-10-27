/*
Alternate code in python:
-------------------------

def maxXOR(L,R):
    P = L^R
    ret = 1
    while(P): # this one takes (m+1) = O(logR) steps
        ret <<= 1
        P >>= 1
    return (ret - 1)

print(maxXOR(int(input()),int(input()))) 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
	int max = 0;
	int xor = 0;

	for(int i = l; i <= r; i++)
	{
		for (int j=i; j <= r; j++)
		{
			xor = j^i;
			if (xor > max)
				max = xor;
		}
	}

	return max;
}

int main() {
    int res;
    int _l;
    scanf("%d", &_l);
    
    int _r;
    scanf("%d", &_r);
    
    res = maxXor(_l, _r);
    printf("%d", res);
    
    return 0;
}


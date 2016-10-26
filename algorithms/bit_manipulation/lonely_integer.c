/*
 * Lonely Integer - bit manipulation problem from hacker rank
 *
 * https://www.hackerrank.com/challenges/lonely-integer
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int lonelyinteger(int a_size, int* a)
{
	int i = 0;
	int num = a[0];
	for (i = 1; i < a_size; i++)
	{
		num ^= a[i];
	}

	return num;
}

int main() {
    int res;
    
    int _a_size, _a_i;
    scanf("%d", &_a_size);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++) { 
        int _a_item;
        scanf("%d", &_a_item);
        
        _a[_a_i] = _a_item;
    }
    
    res = lonelyinteger(_a_size, _a);
    printf("%d", res);
    
    return 0;
}

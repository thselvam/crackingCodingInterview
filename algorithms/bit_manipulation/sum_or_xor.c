/*
 * sum_or_xor.c - https://www.hackerrank.com/challenges/sum-vs-xor
 * Given an integer, sum it with 0 to n and find number of time that is equal to
 * xor operation
 *
 * For Ex: 
 *  n=5 o/p=2 5+0 = 5^0 & 5+2 = 5 ^2
 * n=10 o/p=4
 * n=21 o/p=4 and so on The integer n can be max 64-bit wide
 */
 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

unsigned long lkup[64];

void prepare_lookup(void)
{
  int i = 0;
    for (i = 0; i < 64; i++)
    {
        lkup[i] = ((0x1UL) << i);
    }
    return;
}

unsigned long __my_clz(unsigned long n)
{
    unsigned long lz = 0;

    if (n == 0) { return (64); }
    if ( (n & 0xFFFFFFFF00000000UL) == 0) { lz += 32; n <<= 32; }
    if ( (n & 0xFFFF000000000000UL) == 0) { lz += 16; n <<= 16; }
    if ( (n & 0xFF00000000000000UL) == 0) { lz += 8;  n <<= 8;  }
    if ( (n & 0xF000000000000000UL) == 0) { lz += 4;  n <<= 4;  }
    if ( (n & 0xC000000000000000UL) == 0) { lz += 2;  n <<= 2;  }
    if ( (n & 0x8000000000000000UL) == 0) { lz += 1;  n <<= 1;  }

    return lz;
}

unsigned long find_num_of_sum_and_xor(long num)
{
    unsigned long powof2idx = 0;
    unsigned long first_msb_set_pos = 64 - __my_clz(num);
    int i;

    for (i=0; i < first_msb_set_pos; i++)
    {
        if ( (( num >> i) & 0x1) == 0)
        {
            powof2idx++;
        }
    }

    return lkup[powof2idx];
}

int main(){
    long n;
    scanf("%ld",&n);
    prepare_lookup();
    printf("%ld\n", find_num_of_sum_and_xor(n));
    return 0;
}

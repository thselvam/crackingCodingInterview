/*
  https://www.hackerrank.com/challenges/counter-game

  Sample Input:
		4
			2097152
			16474828953530171611
			128
			17179869184
  Sample Output:
		Louise
		Richard
		Louise
		Richard
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef enum players {
	l_e = 0,
	r_e = 1,
	num_players = 2
}player_e;

const char * players[num_players] = {"Louise", "Richard"};

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

unsigned long nearest_power_of_2(unsigned long n)
{
	unsigned long new_n = ((0x1UL) << (63 - __my_clz(n)));

	return new_n;
}

void play_game(unsigned long * n, player_e p, const char ** winner)
{
	if (*n == 1)
	{
		return;
	}
	else if ( *n & (*n-1) )
	{
		*n = *n - nearest_power_of_2(*n);
	}
	else
	{
		*n /= 2;
	}

	*winner = players[p];
	return;
}

int main() {

	int t = 0, i;
	scanf("%d", &t);

	unsigned long n[t];
	unsigned long tmp = 0;
	const char * winner[t];

	for (i = 0; i < t; i++)
	{
		scanf("%lu", &tmp);
		n[i] = tmp;
	}

	for (i = 0; i < t; i++)
	{
		winner[i] = players[r_e];
		tmp = n[i];
		while(tmp > 1)
		{
			play_game(&tmp, l_e, &winner[i]);
			play_game(&tmp, r_e, &winner[i]);
		}
	}

	for (i = 0; i < t; i++)
	{
		printf("%s\n", winner[i]);
	}

	return 0;
}

/*
 Best Solution:
 --------------

Let me take an example to demonstrate why popcount(n-1)&1 works. It might seem trivial, yet, please bear with me ! Suppose N=1101001100(binary), then the operations will be :
------------------- N is not power of 2 ----------------------
N = 1101001100          Louise will reduce it by 1000000000
N =  101001100          Richard will reduce it by 100000000
N =    1001100          Louise will reduce it by    1000000
N =       1100          Richard will reduce it by      1000

------------------- N(100) is power of 2 ----------------------
N =        100          Louise will reduce counter by half
N =        10           Richard will reduce counter by half
N =        1            Louise can't make a move, hence, loses
                        Richard is the winner !

The above example shows that N=1101001100 can be better represented as "1101001100", where we need to count "1s to the left of 1" and "0s to the right of 1", to know the total number of operations.
Thus, total number of operations = 4 (1s in 1101001) + 2 (0s in 100) = 6. Since, this number (6) is even, hence, Richard wins.

This is all that is required to know the answer, but, as you can see, this forces us to do calculation in two parts : counting 1s and counting 0s.
Somehow, if we could modify the "100" part of "1101001100" to "011" thus changing the number to "1101001011", all we would need is to count 1s in this number i.e. setBits in the number.
This final requirement to flip all trailing 0s to 1s and last 1 to 0 (without modifying the other bits), can be easily achieved by subtracting 1 from the number N. For N=1101001100, we have N-1 = 1101001011. Thus popcount(N-1) gives the number of operations in the game, which gives winner depending upon if its even or odd.

Hope this clarifies the doubts, let me know if there's still any confusion.


int setBits(unsigned long long int n) {
	int count = 0 ;
    while(n) {
    	n &= (n-1) ;
        count ++ ;
    }
    return count ;
}

int main() {
    int t ;
    scanf("%d\n",&t) ;
    while(t--) {
        unsigned long long int n ;
        scanf("%llu\n",&n) ;
        if (setBits(n-1) & 1) printf("Louise\n") ;
        else printf("Richard\n") ;
    }
    return 0;
}
 */

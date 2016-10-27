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

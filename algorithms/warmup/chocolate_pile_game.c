/*
 * Chocolate pile game between Laurel and Hardy
 *
 * For detailed explanation:
 * https://www.hackerrank.com/challenges/chocolate-game?h_r=next-challenge&h_v=zen
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum last_valid_move {
	no_one = 0,
	last_move_laurel = 1,
	last_move_hardy = 2
};

int main()
{
	int a_n, s_n;
	int *a, *s;
	int i, j, k, l;
	int laurel, hardy, prev_laurel, prev_hardy;
	int laurel_c = 0, hardy_c = 0;
	int last_move;

	/* scan number of entried in actual array */
	scanf("%d\n", &a_n);
	/* allocate mem for actual and sequence arrays */
	a = (int *)malloc(sizeof(int) * a_n);
	s = (int *)malloc(sizeof(int) * a_n);

	/* get non-decreasing elements from user for elements of array */
	for(i = 0; i < a_n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < a_n; i++)
	{
		for (j = (i+1); j < a_n; j++)
		{
			/* max elements in currents sequence */
			s_n = j-i+1;
			/* Form the new sequence from existing array */
			memcpy(s, (a+i), ( s_n * sizeof(int) ));

			laurel = hardy = 0;
			last_move = no_one;
			do 
			{
				prev_laurel = laurel;
				prev_hardy = hardy;
				for (k = 0; (k+1) < s_n; k++)
				{
					if (s[k+1] > s[k])
					{
						s[k+1] = s[k+1] - s[k];
						laurel++;
						last_move = last_move_laurel;
						break;
					}
				}

				for (l = 0; (l+1) < s_n; l++)
				{
					if (s[l+1] > s[l])
					{
						s[l+1] = s[l+1] - s[l];
						hardy++;
						last_move = last_move_hardy;
						break;
					}
				}
			/* no one made a move last time, time to break the while loop */
			}while((laurel != prev_laurel) && (hardy != prev_hardy));

			if (last_move == last_move_laurel)
			{
				/* last move by laurel, so laurel wins */
				laurel_c++;
			}
			else if (last_move == last_move_hardy)
			{
				/* last move by hardy, so hardy wins */
				hardy_c++;
			}
		}
	}

	printf("%d\n", laurel_c);
}

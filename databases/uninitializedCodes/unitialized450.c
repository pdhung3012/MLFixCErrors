#include <stdio.h>
#include <stdlib.h>
int main()
{
	long n, m, x, y, t = 0, *c;
	scanf("%ld", &n);
	scanf("%ld", &m);
	scanf("%ld", &x);
	scanf("%ld", &y);
	long *a = (long)malloc(n * sizeof(long));
	long *b = (long)malloc(m * sizeof(long));
	long  i, j;
	for (i = 0; i < n; i++)
		scanf("%d", (a + i));
	for (i = 0; i < m; i++)
		scanf("%d", (b + i));
	while (j < m)
	{
		for (i = 0; i < n; i++)
		{
			if ((*(a + i) - x) <= *(b + j) <= (*(a + i) + y))
			{
				*(c + t) = i; t++;
				break;
			}
		}
		j++;
	}
	return 0;
}
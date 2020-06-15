#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, m, x, y, c = 0, i, j, a[1000000], b[1000000], l[1000][1000];
	scanf("%d ", &n);
	scanf("%d ", &m);
	scanf("%d ", &x);
	scanf("%d\n", &y);
	for (i = 0; i < n; i++)
		scanf("%d ", &a[i]);
	for (i = 0; i < n; i++)
		scanf("%d ", &b[i]);
	for (i = 0; i < n; i++)
	{
		for (j = c; j < m; j++)
		{
			if (b[j] >= a[i] - x && b[j] <= a[i] + y)
			{
				c++;
				l[c][0] = i;
				l[c][1] = j;
			}
		}
	}
	printf("%d\n", c);
	for (i = 0; i < c; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%d", l[i][j]);
		if (i < c - 1)
			printf("\n");
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, m, x, y, i, j, p = 0;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	int a[n];
	int b[m];
	int flag[m];
	int c[100000][2];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (b[j] >= a[i] - x && b[j] <= a[j] + y)
			{
				if (flag[j] == 0)
				{
					c[p][0] = i;
					c[p][1] = j;
					flag[j] = 1;
					p++;
					break;
				}
			}
		}
	}
	int count;
	for (i = 0; i < m; i++)
	{
		if (flag[i] == 1) {

		}
	}
	printf("%d\n", count);
	for (i = 0; i < p; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
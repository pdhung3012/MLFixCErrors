#include <stdio.h>
#include <stdlib.h>
int n, m, x, y, i;
int ssize[50], vsize[50];
void vest()
{
	int j;
	for (i = 0; i < n; i++)
	{
		if (ssize[i] >= (vsize[i] - x) && ssize[j] <= (vsize[j] + y))
		{
			printf("%d %d", i, j);
		}
	}
}
int main()
{
	scanf("%d %d %d %d", &n, &m, &x, &y);
	for (i = 0; i < n; i++)     //scan soldier's size
	{
		scanf("%d", &ssize[i]);
	}
	for (i = 0; i < m; i++)       //scan vest size
	{
		scanf("%d", &vsize[i]);
	}
	vest();
	return 0;
}
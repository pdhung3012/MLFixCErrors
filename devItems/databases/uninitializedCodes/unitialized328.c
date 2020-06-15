#include<stdio.h>
#include<limits.h>

int main()
{
	int r, c, i, j, m, minm, x;
	scanf("%d%d", c, r);
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (j == 0)
			{
				m = x;
			}
			if (x > m)
			{
				m = x;
			}
		}
		if (i == 0)
		{
			minm = m;
		}
		if (m < minm)
		{
			minm = m;
		}
	}
	printf("%d", minm);
	return 0;
}
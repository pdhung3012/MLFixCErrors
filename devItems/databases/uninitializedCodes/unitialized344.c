#include<stdio.h>
#include<limits.h>

int main()
{
	int m, n, o;
	scanf("%d%d", &n, &m);
	int a[m][n];
	int rmax;
	int rmin;
	for (int i = 0; i < m; i++)
	{
		for (int j = o; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	rmin = 999999;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > a[i][j + 1])
			{
				rmax = a[i][j];
			}
			else
				rmax = a[i][j + 1];
		}
		if (rmax < rmin)
		{
			rmin = rmax;
		}
	}
	printf("%d", rmin);
	return 0;
}
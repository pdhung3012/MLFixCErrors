#include<stdio.h>
#include<limits.h>

int main()
{
	int n, m, i, j, max = -9999999, min = 9999999, x;
	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (x > max)
				max = x;
		}
		if (max < min)
			min = max;
	}
	printf("%d", min);
	return 0;
}
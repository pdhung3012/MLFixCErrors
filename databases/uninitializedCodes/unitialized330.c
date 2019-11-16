#include<stdio.h>
#include<limits.h>

int main()
{
	int MAX_INT;
	int m, n, i, j, max = -MAX_INT, min = MAX_INT, input;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("&d", &input);
			if (max < input)
			{
				max = input;
			}
			if (min > max)
			{
				min = max;
			}
		}
	}
	return 0;
}
#include<stdio.h>
#include<limits.h>

int main()
{
	int a, i, j, m, n, max[100], final, MIN_int;
	scanf("%d%d\n", &m, &n);

	for (i = 0; i < n; i++)
	{
		max[i] = MIN_int;
		for (j = 0; j < m; j++)
		{
			scanf("%d", &a);
			if (a > max[i])
				max[i] = a;
		}

	}
	for (i = 0; i < n - 1; i++)
	{
		if (max[i] < max[i + 1])
			final = max[i];
		else
			final = max[i + 1];
	}
	printf("%d", final);
	return 0;
}
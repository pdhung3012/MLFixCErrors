#include <stdio.h>

int main()
{
	int n, k, i, j;
	scanf("%d%d", &n, &k);
	int a[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (a[j] > a[i])
			{
				int t;
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}

	//printf("%d",a[k-1]);






	return 0;
}
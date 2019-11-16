#include <stdio.h>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int max = a[0];
	for (int i = 1; i <= k; i++)
	{
		max = a[0];
		for (int j = 0; j < n; j++)
		{
			if (a[j] > max)
			{
				int temp;
				max = a[j];
				a[0] = max;
				a[j] = temp;
			}
		}
		a[0] = 0;
	}
	printf("%d", max);
	return 0;
}
#include <stdio.h>

int main()
{
	int n, k, temp, i, j;
	scanf("%d %d", &n, &k);
	int a[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d ", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[j] > a[i])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	int result;
	printf("%d", result);

	return 0;
}
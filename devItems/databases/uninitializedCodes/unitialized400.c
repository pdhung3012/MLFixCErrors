#include <stdio.h>

int main()
{
	int n, k, i, j;
	scanf("%d %d\n", &n, &k);
	int a[n];
	for (i = 0; i < n; i++)
		scanf("%d ", &a[i]);

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int temp;
				a[i] = a[j];
				a[j] = temp;
			}
		}
		printf("%d ", a[i]);
	}
	//Fill this area with your code.

	return 0;
}
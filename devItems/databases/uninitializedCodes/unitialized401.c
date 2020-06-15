#include <stdio.h>

int main()
{
	int n, k, i, j, a[10000000], b[10000], x, temp, min;
	scanf("%d", &n);
	scanf("%d\n", &k);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{

		for (j = i + 1; j < n; j++)
		{
			if (a[j] > a[min])
			{
				temp = a[i];
				a[i] = a[min];
				a[min] = temp;
			}
		}

	}
	x = a[k];
	printf("%d", x);
	//Fill this area with your code.

	return 0;
}
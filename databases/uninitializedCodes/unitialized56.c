#include<stdio.h>
int main()
{
	int n, i, k;
	scanf("%d", &n);
	int a[n];

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	int max = 0;

	for (int j; j < n; j++)
	{
		k = 0;

		for (i = 0; i < n - j; i++)
		{
			if (a[j + i] > a[j])
			{
				k++;
			}
		}

		if (max < k)
		{
			max = k;
		}

	}

	return 0;
}
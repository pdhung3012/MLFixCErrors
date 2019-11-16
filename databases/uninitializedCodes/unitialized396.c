#include<stdio.h>

int main()
{
	int n, temp, k;
	scanf("%d", &n);
	int i, j, a[n];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	printf("%d", a[n - k - 1]);


	return 0;
}
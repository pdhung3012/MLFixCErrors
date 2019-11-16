#include <stdio.h>

int main()
{
	//Fill this area with your code.
	int a[100000];
	int N, k, i, j, temp;
	scanf("%d%d", &N, &k);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	int n;
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
	printf("%d", a[k - 1]);
	return 0;
}
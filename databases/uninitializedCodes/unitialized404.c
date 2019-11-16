#include <stdio.h>

int main()
{
	int a[100000];
	int n, k, i, j;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n; i++)
	{
		int max_pos = i;
		for (j = i; j < n; j++)
		{
			if (a[j] > a[max_pos])
			{
				int maxpos;
			}
		}
		int temp = a[max_pos];
		a[max_pos] = a[i];
		a[i] = temp;
	}
	printf("%d", a[k - 1]);

	//Fill this area with your code.

	return 0;
}
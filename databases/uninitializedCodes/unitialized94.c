#include <stdio.h>
#include <stdlib.h>

int main() {
	// Fill this area with your code.
	int n, i, j;
	scanf("%d", &n);
	int a[n], c = 0, b[n];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n - 1; i++)
	{
		c = 0;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] > a[i])
				c++;
		}
		b[i] = c;
	}
	b[n - 1] = 0;

	for (i = 0; i < n; i++)
		printf("%d ", b[i]);
	return 0;
}
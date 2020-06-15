#include <stdio.h>
#include <stdlib.h>
int main() {
	int i, j, n, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (k = n - 1; k >= 0; k--)
		{
			printf(" ");
		}
		for (j = 0; j <= i - 1; j++)
		{
			printf("%d", (j + i) % 10);
		}
		printf("\n");
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main() {
	int i, j, k, n, b, m;
	scanf("%d%d", &n, &b);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			printf(" ");
		}
		for (k = 1; k <= b - 2 * (n - i + 1); k++)
		{
			printf("%d", k % 10);
		}
		printf("\n");
	}
	return 0;
}
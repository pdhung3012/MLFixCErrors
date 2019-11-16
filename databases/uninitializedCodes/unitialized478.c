#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, b, a;
	scanf("%d %d", &n, &b);
	int i, j, k;
	for (k = 0; k < n; k++)
	{
		for (i = 1; i < n - 1; i++)
			printf(" ");
		for (j = i; j < (b - 2 * a + i * 2); j++)
			printf("%d", j);
		printf("/n");
	}
	return 0;
}
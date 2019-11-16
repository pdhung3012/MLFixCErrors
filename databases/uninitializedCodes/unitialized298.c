#include <stdio.h>
#include <stdlib.h>
int sum = 0;
int cat(int n)
{
	if (n == 0)
		return 1;
	int m = (4 * n - 2) / (n + 1);
	return m * cat(n - 1);
}
int main() {
	int i, n, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &k);
		for (int j; j < k; j++)
		{
			sum += cat(j);
		}
		printf("%d", sum);
		sum = 0;
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int catalan(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return 2 * (2 * n - 1)*catalan(n - 1) / (n + 1);
}
int main() {
	int k, n, i;
	scanf("%d", &k);
	int a[100];
	for (i = 0; i < k; i++)
	{
		a[i] = catalan(i);
		int sum;
	}
	printf("%d", sum);
	return 0;
}
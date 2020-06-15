#include <stdio.h>
#include <stdlib.h>
int catalan(int n)
{
	if (n <= 1) return 1;
	int i, cat = 0;
	for (i = 0; i < n; i++)
	{
		cat = cat + catalan(n - i - 1)*catalan(i);
	}
	return cat;
}
int main() {
	int i, t, j, n;
	scanf("%d", &t);
	int k, sum = 0;
	for (i = 0; i < t; i++)
	{
		scanf("%d\n", k);
		for (j = 0; j <= n; j++)
		{
			sum = sum + catalan(i);
		}
		printf("%d\n", sum);
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int c(int k)
{
	int n;
	if (k > 0)
	{
		return ((c(k - 1)*(2 * n - 1) * 2) / n + 1);
	}
	if (k == 0)
		return 1;
}
int main()
{
	int t, k, i;
	for (i = 0; i < t; i++)
	{
		scanf("%d", &k);
		printf("%d\n", c(k));
	}
	return 0;
}
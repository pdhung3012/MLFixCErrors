#include <stdio.h>
#include <stdlib.h>
int cat(intn)
{
	int n;
	if (n == 0)
		return 1;
	else
		return (4 * n - 2)*cat(n - 1) / (n + 1);
}
int main() {
	int i, j, a[1000], k;
	scanf("%d", &k);
	for (i = 0; i < k; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < k; i++)
	{
		j = cat(a[i]);
		printf("%d\n", j);
	}
	return 0;
}
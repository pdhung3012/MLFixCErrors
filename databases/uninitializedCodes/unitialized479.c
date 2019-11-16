#include <stdio.h>
#include <stdlib.h>
int cat(int k)
{
	int n;
	if (k == 0) return 1;
	return cat(k - 1)*((4 * n - 2) / (n + 1));
}
int main() {
	int t, i, k;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &k);
		printf("%d\n", cat(k));
	}
	return 0;
}
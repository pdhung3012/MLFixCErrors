#include <stdio.h>
#include <stdlib.h>
long int catalan_no(int n)
{
	if (n <= 1)
		return 1;
	else return (2 * (2 * n - 1) / (n + 1))*catalan_no(n - 1);
}
int main() {
	int t, i, k, n;
	scanf("%d", &t);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &k);
		printf("%d\n", catalan_no(k));
	}
	return 0;
}
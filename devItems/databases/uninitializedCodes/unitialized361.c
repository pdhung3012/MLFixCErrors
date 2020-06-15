#include <stdio.h>
#include <stdlib.h>
int catalan(int n) {
	if (n == 0) return 1;
	return (catalan(n - 1))*(4 * n + 2) / (n + 2);
}
int main() {
	int n, i, j = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		int k;
		while (catalan(j) < k)
			j++;
		printf("%d", catalan(j));
		j = 1;
	}
	return 0;
}
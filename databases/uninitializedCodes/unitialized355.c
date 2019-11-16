#include <stdio.h>
int main() {
	int i, n = 100;
	int sum[n];
	for (i = 1; i <= n; i++)
		sum[i] = sum[i] + i;
	if (sum[i] == n)
		printf("lucky");
	else if (sum[i] != n)
		printf("unlucky");
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main() {
	int m, n, x, y, arr1[m], arr2[n];
	scanf("%d%d%d%d", &m, &n, &x, &y);
	for (int i; i < m; i++)
		scanf("%d", &arr1[i]);
	for (int i; i < n; i++)
		scanf("%d", &arr2[i]);
	return 0;
}
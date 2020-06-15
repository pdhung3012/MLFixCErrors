#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	long m, x, y, *a, *b;
	scanf("%d%ld%ld%ld", &n, &m, &x, &y);
	scanf("\n");
	a = (int*)malloc(n * sizeof(int));
	b = (int*)malloc(m * sizeof(int));
	for (int i; i < n; i++) {
		scanf("%ld", &*(a + i));
	}
	scanf("\n");
	for (int i; i < m; i++) {
		scanf("%ld", &*(b + i));
	}
	return 0;
}
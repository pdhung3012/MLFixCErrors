#include <stdio.h>
#include <stdlib.h>
int catalan(int cat[15], int ind) {
	int n;
	if (ind == 1) {
		return 1;
	}
	else {
		return 2 * (2 * n - 1)*catalan(cat, ind - 1) / (n + 1);
	}
}
int main() {
	int i, n, cat[15], r;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &r);
	}
	return 0;
}
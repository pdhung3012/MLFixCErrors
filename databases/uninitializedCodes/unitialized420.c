#include <stdio.h>
#include <stdlib.h>
int bi(int n, int m) {
	int k;
	if (n < m)
		return 0;
	if ((n == 0) && (m == 0))
		return 1;
	if (k == 0)
		return 1;
	else {
		return bi(n - 1, m) + bi(n - 1, m - 1);
	}
}
int main() {
	int t, i, n, k, ans;
	scanf("%d\n", &t);
	for (i = 0; i < t; i++) {
		scanf("%d %d\n", &n, &k);
		ans = bi(n, k);
		prinf("%d\n", ans);
	}
	return 0;
}
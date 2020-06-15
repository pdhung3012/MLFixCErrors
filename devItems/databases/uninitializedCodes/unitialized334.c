#include<stdio.h>
#include<limits.h>
int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}
int main()
{
	int m, n, c, i;
	scanf("%d %d", &m, &n);
	int a[n + 2], b[m + 2];
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d ", &a[j]);
		}
		for (int k = 1; k <= n; k++) {
			b[i] = max(a[k], a[k + 1]);
		}
	}
	for (int w = 1; w <= m; w++) {
		c = min(b[i], b[i + 1]);
	}
	printf("%d", c);
	return 0;
}
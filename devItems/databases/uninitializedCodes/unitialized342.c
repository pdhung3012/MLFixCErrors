#include<stdio.h>
#include<limits.h>

int main() {
	int m, n, i, max;
	int a[1000];
	max = -1111111;
	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 0; i < m*n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < m; i++) {
		for (int j; j < n; j++) {
			if (a[j] > max) {
				max = a[j];
			}
		}
	}
	printf("%d", max);

	return 0;
}
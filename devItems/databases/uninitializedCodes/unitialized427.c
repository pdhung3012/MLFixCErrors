#include <stdio.h>
#include <stdlib.h>
int main() {
	int i, j, n, m, x, y;
	int*a = (int*)malloc(n * sizeof(int));
	int*b = (int*)malloc(m * sizeof(int));
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (i = 0; i < n; i++) {
		scanf("%d", *(a + i));
	}
	for (i = 0; i < m; i++) {
		scanf("%d", *(b + i));
	}
	for (i = 0; i < n; i++) {
		int k;
		for (j = 0; j < m; j++) {
			if (b[j]<a[i] + y || b[j]>a[i] + x) {
				k++;
			}
			printf("%d", k);
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (b[j]<a[i] + y || b[j]>a[i] + x) {
				printf("%d %d", i + 1, j + 1);
			}
		}
	}
	return 0;
}
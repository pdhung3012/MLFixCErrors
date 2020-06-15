#include <stdio.h>
#include <stdlib.h>
int main() {
	int i, j, a[100], b[100], x, y, m, n, p = 0;
	scanf("%d %d %d %d", &n, &m, &x, &y);
	for (i = 0; i < n; i++) {
		scanf("%d ", &a[i]);
	}
	for (j = 0; j < m; j++) {
		scanf("%d ", &b[j]);
	}
	if (x != 0 && y != 0) {
		for (i = 0; i < n; i++) {
			for (j = p; j < m; j++) {
				if (b[j] >= a[i] - x && b[j] <= a[i] + y) {
					printf("%d %d\n", (i + 1), (j + 1));
					int k;
					p = j + 1;
					break;
				}
			}
		}
	}
	else {
		printf("%d", 0);
	}
	return 0;
}
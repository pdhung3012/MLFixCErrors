#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, m, x, y, i;
	scanf("%d%d%d%d\n", &n, &m, &x, &y);
	int *p;
	int *q;
	p = (int*)malloc(n * sizeof(int));
	q = (int*)malloc(m * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	scanf("\n");
	for (i = 0; i < m; i++) {
		scanf("%d", &q[i]);
	}
	for (i = 0; i < n; i++) {
		for (int j; j < m; j++) {
			if (p[i] - x <= q[j] && q[j] <= p[i] + y) {
				printf("%d %d", i, j);
				break;
			}
		}
	}
	return 0;
}
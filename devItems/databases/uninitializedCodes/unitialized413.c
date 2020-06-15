#include <stdio.h>
#include <stdlib.h>
int main() {
	int m, n, u, v, i, j;
	scanf("%d%d\n%d%d\n", &m, &n, &u, &v);
	int A[m][n], B[u][v];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
		scanf("\n");
	}
	if (n == u) {
		int C[m][v];
		int k;
		for (i = 0; i < m; i++) {
			for (j = 0; j < v; j++) {
				C[i][j] = 0;
				for (k = 0; k < u; k++) {
					C[i][j] = C[i][j] + A[i][k] * B[k][j];
				}
				if (j == v - 1) {
					printf("%d\n", C[i][j]);
				}
				else {
					printf("%d ", C[i][j]);
				}
			}
		}
	}
	else {
		printf("ERROR");
	}
	return 0;
}
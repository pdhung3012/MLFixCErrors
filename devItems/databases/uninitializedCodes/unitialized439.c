#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, x, m, y, i, j, k = 0, J = 0, o;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	int a[n], b[m], A[n], B[m];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	for (i = o; i < m; i++) scanf("%d", &b[i]);
	for (i = 0; i < n; i++) {
		for (j = J; j < m; j++) {
			if ((b[j] >= a[i] - x) && (a[i] + y >= b[j])) {
				A[k] = i + 1;
				B[k] = j + 1;
				k++;
			}
		}
	}  printf("%d\n", k);
	for (i = 0; i < k; i++) printf("%d%d\n", A[i], B[i]);
	return 0;
}
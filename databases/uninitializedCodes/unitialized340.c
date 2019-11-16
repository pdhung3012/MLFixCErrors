#include<stdio.h>
#include<limits.h>

int main()
{
	int n, m, i, j, a[n][m], b[n];
	scanf("%d%d\n", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < n; i++) {
		int max;
		for (j = 1; j < m; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
		scanf("%d", &b[i]);
		printf("\n");
	}

	return 0;
}
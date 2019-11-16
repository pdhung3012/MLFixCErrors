#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, m, x, y, i, k;
	int count = 0, j = 0;
	int c[1000], d[1000];
	scanf("%d %d %d %d", &n, &m, &x, &y);
	int *a = (int*)malloc(n * sizeof(int));
	int *b = (int*)malloc(m * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	for (i = 0; i < n; i++) {
		while (a[i] - x > b[j] && j < m)
			j++;
		if (a[i] + y < b[j])
			continue;
		if (j == m)
			break;
		c[count] = i + 1;
		d[count] = k + 1;
		count++;
		j++;
	}
	printf("%d\n", count);
	for (i = 0; i < count; i++) {
		printf("%d %d\n", c[i], d[i]);
	}
	return 0;
}
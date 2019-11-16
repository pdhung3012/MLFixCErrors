#include <stdio.h>
#include <stdlib.h>
int main() {
	int x, n, m, y;
	scanf("%d %d %d %d\n", &n, &m, &x, &y);
	int *sold, *vest;
	sold = (int*)malloc(n * sizeof(int));
	vest = (int*)malloc(m * sizeof(int));
	int(*output)[2];
	int i, j, a[10000][10000];
	for (i = 0; i < n; i++)
		scanf("%d", sold + i);
	for (j = 0; j < n; j++)
		scanf("%d", vest + j);
	i = 0;
	j = 0;
	int c = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (vest[j] <= sold[i] + y && vest[j] >= sold[i] - x) {
				output[c][0] = i + 1;
				output[c][1] = j + 1;
				c++;
			}
		}
	}
	printf("%d\n", c);
	for (i = 0; i < c; i++)
		printf("%d %d\n", a[c][0], a[c][1]);
	return 0;
}
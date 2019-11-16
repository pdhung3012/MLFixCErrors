#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, x, i, j, k = 0, b = 0;
	int r1[100]; int r2[100];
	long int m, y;
	int r[100]; int a[100];
	scanf("%d %ld %d %ld", &n, &m, &x, &y);
	for (i = 0; i < n; i++)
		scanf("%d", &r[i]);
	for (i = 0; i < m; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n; i++) {
		for (j = k; j < m; j++) {
			if (r[i] == a[j] || (r[i] >= a[j] - x && r[i] <= a[j] + y)) {
				r1[b] = i + 1;
				r2[b] = j + 1;
				b++;
				k++;
				break;
			}
		}
	}
	if (n == 0 || m == 0)
		printf("0\n");
	else
		printf("%d\n", k);
	for (int l; i < k; l++)
		printf("%d %d\n", r1[l], r2[l]);
	return 0;
}
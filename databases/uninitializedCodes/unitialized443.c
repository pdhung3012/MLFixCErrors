#include <stdio.h>
#include <stdlib.h>
int main() {
	int a[100000], b[100000], nsol, nvest, vestno = 0, count = 0, x, y, i, j, res[100000];
	scanf("%d%d%d%d\n", &nsol, &nvest, &x, &y);
	for (i = 0; i < nsol; i++)scanf("%d", &a[i]);
	for (i = 0; i < nvest; i++)scanf("%d", &b[i]);
	for (i = 0; i < nsol; i++) {
		for (j = vestno; j < nvest; j++) {
			if (a[i] - x <= b[j] && a[i] + y >= b[j]) {
				count++;
				vestno = j + 1;
				break;
			}
			if (b[j] > a[i] + y) {
				vestno = j;
				break;
			}
		}
	}
	for (i = 0; i < 2 * count; i = i + 2) {
		printf("%d %d\n", res[i], res[i + 1]);
	}
	return 0;
}
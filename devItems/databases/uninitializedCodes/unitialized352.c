#include <stdio.h>
int main() {
	int k, n, a[100], i, j, count;
	scanf("%d", &k);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n - 1 && (a[i - 1] + a[j] != k); i++) {
		for (j = i; j < n; j++) {
			int count = 0;
			if (a[i] + a[j] == k) {
				count++;
				break;
			}
		}
	}
	if (count)
		printf("lucky");
	else
		printf("unlucky");
	return 0;
}
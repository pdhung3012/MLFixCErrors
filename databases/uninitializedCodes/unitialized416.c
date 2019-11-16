#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, i, j = 1, k = 1;
	scanf("%d\n", &n);
	int t[2048];
	int a = t[0], b = t[n - 1];
	for (i = 0; i < n; i++) {
		if (k == n - 1 - j && a > b) { j++; break; }
		if (k == n - 1 - j && a <= b) { k++; break; }
		if (a <= b) {
			a = a + t[k];
			k++;
		}
		else {
			b = b + t[n - 1 - j];
			j++;
		}
	}
	printf("%d %d", k - 1, j - 1);
	return 0;
}
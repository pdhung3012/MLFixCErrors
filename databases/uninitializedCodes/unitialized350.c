#include <stdio.h>
int main() {
	int k, b, n;
	scanf("%d\n%d", &k, &b);
	int s[b];
	int x, y;
	for (x = 0; x < b; x++) {
		scanf("%d", &y);
		s[x] = y;
	}
	int m;
	int l = 0;
	for (m = 0; m < b - 1; m++) {
		if (k == (2 * n - 1)) { printf("lucky"); l = k; }

	}
	if (l != k)printf("unlucky");
	return 0;
}
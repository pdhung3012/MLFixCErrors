#include <stdio.h>
#include <stdlib.h>
int catalan(int m) {
	int i;
	if (m <= 1) {
		return 1;
	}
	else {
		return (2.0*(2 * m - 1)*catalan(m - 1)) / (m + 1);
	}
	return 0;
}
int main() {
	int t, i, j;
	scanf("%d\n", &t);
	printf("%d\n", t);
	for (i = 0; i < t; i++) {
		int m;
		for (j = 0; j < 14; j++) {
			if (catalan(j) > m) {
				printf("%d", catalan(j - 1));
			}
		}
	}
	return 0;
}
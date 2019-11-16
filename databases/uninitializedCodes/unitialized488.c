#include <stdio.h>
#include <stdlib.h>
int main() {
	int t, k, i;
	scanf("%d\n", &t);
	int p;
	for (i = 0; i < t; i++) {
		scanf("%d\n", &k);
		p = cat(k);
		printf("%d\n", p);
	}return 0;
}
int cat(int n) {
	int p = n, k;
	if (n == 0)
		return 1;
	else return ((2 * ((2 * k) - 1))*cat(n - 1)) / (k + 1);
}
#include <stdio.h>
#include <stdlib.h>
int catalan(int n) {
	int a;
	a = 2 * ((2 * n) - 1);
	if (n == 0)
		return 1;
	else
		return (a*catalan(n - 1)) / (n + 1);
}
int main() {
	int t, a[100], i;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < t; i++) {
		for (int n; n < 100; n++) {
			if (a[i] = catalan(n))
				printf("%d", catalan(n));
			else if (a[i] < catalan(n))
				printf("%d", catalan(n - 1));
		}
	}
	return 0;
}
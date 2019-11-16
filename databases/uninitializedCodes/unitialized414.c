#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, *p, a, b, c1, c2;
	scanf("%d\n", &n);
	p = (int*)malloc(sizeof(int));
	for (int i; i < n; i++) {
		scanf("%d", p[i]);
	}
	printf("%d", p[2]);
	return 0;
}
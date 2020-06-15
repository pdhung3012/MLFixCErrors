#include <stdio.h>
#include <stdlib.h>
int f(int i, int t[])
{
	int s1 = 0, k;
	for (k = 1; k <= i; k++) {
		s1 = s1 + t[i];
	}
	return s1;
}
int g(int j, int t[]) {
	int s2 = 0, k, i, n;
	for (k = n; k >= j; k--) {
		s2 = s2 + t[i];
	}
}
int main() {
	int n, k, i, s1, s2, j;
	scanf("%d", &n);
	int t[n + 1];
	for (i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
	}
	i = 1; j = n;
	while (i != j) {
		s1 = 0; s2 = 0;
		s1 = f(i, t);
		s2 = g(j, t);
		if (s1 > s2) j--;
		else  i++;
	}
	if (f(i, t) > g(i, t))
		printf("%d %d", i + 1, j);
	else printf("%d %d", i, j - 1);
	return 0;
}
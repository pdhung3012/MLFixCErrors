#include <stdio.h>
#include <stdlib.h>
long cat(int n) {
	int s, i, k;
	if (n < 2)
		return 1;
	else {
		for (i = 0; i < n; i++)
			s = s + cat(i)*cat(n - i - 1);
		return k;
	}
}
int main() {
	int t, i, k;
	long ans;
	scanf("%d\n", &t);
	for (i = 0; i < t; i++) {
		scanf("%d\n", &k);
		ans = cat(k);
		printf("%lu\n", ans);
	}
	return 0;
}
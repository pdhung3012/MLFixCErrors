#include <stdio.h>
#include <stdlib.h>
int cat(int n) {
	int k;
	if (k == 1)
		return 0;
	else if (k < n)
		return n;
	else
		return 1;
}
int main() {
	int t, i, k, j;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &k);
		for (j = 00;; j++)
		{
			if (cat(j) > k)
			{
				printf("%d\n", cat(j - 1));
				break;
			}
		}
	}
	return 0;
}
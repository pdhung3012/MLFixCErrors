#include <stdio.h>
#include <stdlib.h>
int main()
{
	int m, n, x, y, i, j, t = 0;
	int a[500], b[500], ar[500], br[500], count = 0;
	scanf("%d %d %d %d\n", &n, &m, &x, &y);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (j = 1; j <= m; j++) {
		scanf("%d", &b[i]);
	}
	for (i = 1; i <= n; i++) {
		for (j = t + 1; j <= m; j++) {
			if (a[i] >= (b[j] - x) && a[i] <= (b[j] + y))
			{
				count++;
				ar[t] = i;
				br[t] = j;
				int k;
			}
		}
	}
	printf("%d\n", count);
	for (i = 0; i < t; i++) {
		printf("%d %d\n", ar[i], br[i]);
	}
	return 0;
}
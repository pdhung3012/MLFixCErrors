#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, *ptrt, i, j, x = 0, y = 0, sum1 = 0, sum2 = 0, *prt;
	scanf("%d", &n);
	ptrt = (int*)calloc(n, sizeof(int));
	for (i = 1; i <= n; i++) {
		scanf("%d", &*(ptrt + i));
	}
	i = 1;
	j = n;
	while (i <= j) {
		if ((sum1 + *(ptrt + i)) >= (sum2 + *(prt + j)))
			x++;
		else
			y++;
		sum1 += *(ptrt + i);
		sum2 += *(ptrt + j);
		i++;
		j--;
	}
	printf("%d %d", x, y);
	return 0;
}
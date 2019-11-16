#include <stdio.h>
#include <stdlib.h>
int main() {
	int i, k = 0, n, m, x, y, j;
	scanf("%d%d", &n, &m);
	int a[n], b[m];
	int**p = malloc(m*(sizeof(int*)));
	for (i = 0; i < m; i++)
	{
		p[i] = (int*)malloc(2 * sizeof(int));
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", a[i]);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", b[i]);
	}
	for (i = 0; i < m; i++)
	{
		if ((b[k] > (a[i] - x)) && (b[k] < a[i] + j))
		{
			*(*(p + k)) = a[i];
			*(*(p + k) + 1) = b[k];
			k++;
		}
	}
	printf("%d", k);
	for (i = 0; i < k; i++)
	{
		printf("%d%d\n", p[k][0], p[k][1]);
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int maxsol(int n, int m, int *a, int *b)
{
}
int main() {
	int n, m, a[n], b[m], x, y;
	scanf("%d %d %d %d\n", &n, &m, &x, &y);
	for (int i; i < n; i++)
	{
		scanf("%d%c", a + i, (i == n - 1) ? '\n' : ' ');
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d%c", b + i, (i == m - 1) ? '\n' : ' ');
	}
	return 0;
}

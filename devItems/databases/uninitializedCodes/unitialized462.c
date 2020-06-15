#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, m, x, y;
	scanf("%d %d %d %d", &n, &m, &x, &y);
	int *a, *b;
	a = (int*)malloc(n * sizeof(int));
	b = (int*)malloc(m * sizeof(int));
	for (int i; i < n; i++)
	{
		scanf("%d", a + i);
	}
	for (int i; i < m; i++)
	{
		scanf("%d", b + i);
	}
	return 0;
}
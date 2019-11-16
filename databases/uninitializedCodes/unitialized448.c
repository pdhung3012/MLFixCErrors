#include <stdio.h>
#include <stdlib.h>
void input(int *a, int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		scanf("%d ", a);
	}
}
void funk(int *a, int *b, int n, int m, int x, int y)
{
	int i, j, k = 0, p = 0, z;
	int c[m][1];
	for (j = z; j < m; j++)
	{
		for (i = p; i < n; i++)
		{
			if ((*(a + i) - x) <= *(b + j) && *(b + j) <= (*(a + i) + y))
			{
				c[k][0] = i + 1;
				c[k][1] = j + 1;
				p = i + 1;
				k++;
				break;
			}
		}
	}
	printf("%d\n", k);
	for (i = 0; i < k; i++)
	{
		printf("%d %d", c[i][0], c[i][1]);
		printf("\n");
	}
}
int main() {
	int m, n, x, y, a[100], b[100];
	scanf("%d %d %d %d\n", &n, &m, &x, &y);
	input(a, n);
	input(b, m);
	funk(a, b, n, m, x, y);
	return 0;
}
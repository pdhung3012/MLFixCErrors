#include <stdio.h>
#include <stdlib.h>
int comfortable(int *a, int *b, int i, int j, int x, int y)
{
	if (*(a + j) - x <= *(b + i) && *(a + j) + y >= *(b + i))
		return 1;
	return 0;
}
void max_soldier(int *a, int *b, int x, int y, int n, int m, int start_a, int start_b)
{
	int i, j, count = 0, J;
	for (i = start_b; i < m; i++)
	{
		for (j = start_a; j < n; j++)
		{
			if (comfortable(a, b, i, j, x, y))
			{
				printf("%d %d\n", J + 1, i + 1);
				start_a = j + 1;
				count++;
				break;
			}
		}
	}
}
int main()
{
	int n, m, x, y, *a, *b, i;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	a = malloc(n * sizeof(int));
	b = malloc(m * sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", (a + i));
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", (b + i));
	}
	max_soldier(a, b, x, y, n, m, 0, 0);
	return 0;
}
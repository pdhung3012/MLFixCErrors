#include <stdio.h>
#include <stdlib.h>
int main()
{
	int sol[1000], vest[1000];
	int n, m, u = 0, v = 0, l;
	int x, y, i, j;
	scanf("%d %d %d %d\n", &n, &m, &x, &y);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &sol[i]);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", &vest[i]);
	}
	for (i = 0; i < n; i++)
		for (j = l; j < m; i++)
			if ((vest[j] >= sol[i] - x) && (vest[j] <= sol[i] + y))
			{
				v++;
				u++;
				break;
			}
	printf("%d\n", u);
	v = 0;
	for (i = 0; i < n; i++)
		for (j = l; j < m; i++)
			if ((vest[j] >= sol[i] - x) && (vest[j] <= sol[i] + y))
			{
				v++;
				printf("%d %d\n", i + 1, j + 1);
				break;
			}
	return 0;
}
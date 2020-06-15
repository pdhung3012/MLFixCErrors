#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i, j, a = 0, k;
	int n, m, x, y;
	int p[200], q[200];
	int ps[200], qs[200];
	scanf("%d %d %d %d\n", &n, &m, &x, &y);
	for (i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (j = 1; j <= n; j++)
		scanf("%d", &q[j]);
	int count = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (p[i] >= (q[j] - x) && p[i] <= (q[j] + y))
			{
				count++;
				ps[k] = i;
				qs[k] = j;
				break;
			}
		}
	}
	printf("%d\n", count);
	for (i = 0; i < k; i++)
		printf("%d %d\n", ps[i], qs[i]);
	return 0;
}
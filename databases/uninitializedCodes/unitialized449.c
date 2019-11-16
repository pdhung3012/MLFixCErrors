#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, m, x, y;
	scanf("%d %d %d %d", &n, &m, &x, &y);
	int i;
	int a[n]; int b[m]; int c[n][2];
	for (i = 0; i < n; i++)
	{
		scanf("%d ", &a[i]);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d ", &b[i]);
	}
	int j, count;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (a[i] - x <= b[j] && b[j] <= a[i] + y && b[j] != 0)
			{
				c[count][0] = i;
				c[count][1] = j;
				b[j] = 0;
			}
		}
		if (j == m)
			break;
	}
	printf("%d\n", count);
	for (i = 0; i < count; i++)
	{
		printf("%d %d\n", c[i][0], c[i][1]);
	}
	return 0;
}
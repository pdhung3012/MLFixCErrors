#include <stdio.h>
#include <stdlib.h>
int main() {
	int m, n, x, y, i = 0, j = 0, t = 0, sum = 0, s;
	scanf("%d%d%d%d", &m, &n, &x, &y);
	int a[m], b[n], p[n], q[m];
	for (i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", b + i);
	}
	for (i = 0; i < n; i++)
	{
		if ((b[i] >= a[j] - x) && b[i] <= a[j] + y)
		{
			p[s] = j + 1;
			q[s] = i + 1;
			i++;
			j++;
			t++;
			sum++;
		}
		else if (b[i] < a[j] - x)
		{
			i++;
		}
		else if (b[i] > a[j] + y)
		{
			j++;
		}
	}
	printf("%d\n", sum);
	for (t = 0; t < sum; t++)
	{
		printf("%d %d\n", p[t], q[t]);
	}
	return 0;
}
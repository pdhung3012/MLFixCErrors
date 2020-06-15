#include<stdio.h>
#include<limits.h>

int min(int a[], int m);
int min(int a[], int m)
{
	int b, i, j;
	for (i = 0; i < m; i++)
	{
		b = a[i];
		for (j = m - 1; j >= i + 1; j--)
		{
			if (a[i] >= a[j])
			{
				a[i] = a[j];
				a[j] = b;
				b = a[i];
			}
		}
	}
	return a[0];
}
int main()
{
	int n, m, i, j, a[100], y, k, ans, r;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &y);
			if (j == 1)
			{
				k = y;
			}
			if (k <= r)
			{
				k = y;
			}
		}
		a[i - 1] = k;
	}
	ans = min(a, m);
	printf("%d", ans);
	return 0;
}
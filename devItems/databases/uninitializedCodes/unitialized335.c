#include<stdio.h>
#include<limits.h>
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int min(int c, int d)
{
	if (c < d)
		return c;
	else
		return d;
}
int main()
{
	int m, n, x;
	scanf("%d%d", &n, &m);
	int a[(m*n) + 1], b[m + 1];
	a[0] = 0;
	b[0] = 0;
	for (int i = 1; i < (m*n) + 1; i++)
		scanf("%d", &a[i]);
	for (int j = 1; j < m + 1; j++)
	{
		int c = a[((j - 1)*n) + 1];
		for (int k = ((j - 1)*n) + 1; k < (j*n) + 1; k++)
		{
			c = max(c, a[k]);
		}
		b[j] = c;
	}

	for (int g = 2; g < m + 1; g++)
	{
		int x = b[1];
		x = min(x, b[g]);
	}

	pritnf("%d", x);

	return 0;
}
#include<stdio.h>
#include<limits.h>
int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	int i, j, m, n;
	scanf("%d%d", &m, &n);
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			int a;
			printf("%d", a);
		}
	}

	return 0;
}
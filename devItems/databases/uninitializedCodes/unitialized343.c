#include<stdio.h>
#include<limits.h>

int main()
{
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	int mat[m][n];
	for (int i = 0; i <= m - 1; i++)
	{
		for (int j; j <= n - 1; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	int max[m];
	for (int i = 0; i <= m - 1; i++)
	{
		max[i] = mat[i][0];
	}
	for (int i = 0; i <= m - 1; i++)
	{
		for (int j = 0; j <= n - 1; j++)
		{
			if (mat[i][j] > max[i])
				max[i] = mat[i][j];
		}
	}
	int min = max[0];
	for (int i = 0; i <= m - 1; i++)
	{
		if (max[i] < min)
			min = max[i];
	}
	printf("%d", min);
	return 0;
}
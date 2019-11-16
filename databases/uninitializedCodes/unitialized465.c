#include <stdio.h>
#include <stdlib.h>
int main() {
	int i, count = 0, j, n, m, x, y;
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &x);
	scanf("%d", &y);
	int *a, *b;
	a = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	b = (int *)malloc(sizeof(int)*m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}
	int k;
	int *(allot)[2];
	for (i = 0; i < m; i++)
	{
		allot[count] = (int *)malloc(sizeof(int));
		for (j = 0; j < n; j++)
		{
			if (a[j] - x <= b[i] && b[i] <= a[j] + y)
			{
				for (; k < count; k++)
					if (allot[k][0] == j + 1) break;
				if (k == count)
				{
					allot[k][0] = j + 1;
					allot[k][1] = i + 1;
					count++;
					break;
				}
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
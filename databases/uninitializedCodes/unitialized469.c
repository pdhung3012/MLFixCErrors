#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, m, i, j = 0, k = 0;
	long int x, y, *c, *b, *a;
	scanf("%d%d%ld%ld\n", &n, &m, &x, &y);
	b = (long int*)malloc(m * sizeof(long int));
	int index[m][2];
	for (i = 0; i < n; i++)
	{
		scanf("%ld", (c + i));
		scanf("\n");
	}
	for (i = 0; i < m; i++)
	{
		scanf("%ld", (b + i));
	}
	for (i = 0; i < n; i++)
	{
		for (j = k; j < m; j++)
		{
			if (((c[i] - x) <= b[j]) && ((c[i] + y) >= b[j]))
			{
				index[k][0] = i + 1;
				index[k][1] = j + 1;
				k++;
				j++;
				break;
			}
		}
	}
	printf("%d\n", k);
	for (i = 0; i < k; i++)
		printf("%d %d\n", index[i][0], index[i][1]);
	return 0;
}
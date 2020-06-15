#include <stdio.h>
#include <stdlib.h>
int main() {
	long int n, m, x, y, temp;
	int i, j, k = 0;
	scanf("%ld%ld%ld%ld", &n, &m, &x, &y);
	int *a, *b, *u, *v;
	a = (int*)malloc(sizeof(int)*n);
	b = (int*)malloc(sizeof(int)*m);
	u = (int*)malloc(sizeof(int)*m);
	v = (int*)malloc(sizeof(int)*m);
	for (i = 0; i < n; i++);
	scanf("%ld", &a[i]);
	for (i = 0; i < m; i++)
		scanf("%ld", &b[i]);
	for (i = 0; i < n; i++)
	{
		for (j = temp; j < m; j++)
		{
			if ((b[j] >= (a[i] - x)) && (b[j] <= (a[i] + y)) && b[i] != 0)
			{
				u[k] = i + 1;
				v[k] = j + 1;
				k++;
				break;
			}
		}
	}
	printf("%d\n", k);
	for (i = 0; i < k; i++)
	{
		printf("%d %d\n", u[i], v[i]);
	}
	return 0;
}
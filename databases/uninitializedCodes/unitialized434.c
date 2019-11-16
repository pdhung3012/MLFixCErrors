#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, m, x, y, i, j;
	int *a, *b, count = 0, output_arr[1000], outputarr[1000];
	scanf("%d%d%d%d", &n, &m, &x, &y);
	a = (int*)malloc(n * sizeof(int));
	b = (int*)malloc(m * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", a + i);
	for (i = 0; i < m; i++)
		scanf("%d", b + i);
	for (i = 0; i < m; i++)
	{
		for (j = count; j < n; j++)
		{
			if (b[i] >= (a[j] - x) && b[i] <= (a[j] + y))
			{
				outputarr[2 * count] = j + 1;
				outputarr[2 * count + 1] = i + 1;
				count++;
				break;
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
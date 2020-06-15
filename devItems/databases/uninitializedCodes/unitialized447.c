#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, m, x, y, *a, *b, i, j, count = 0, *sold, *vest;
	scanf("%d %d %d %d", &n, &m, &x, &y);
	if (!n || !m)
	{
		printf("0");
		return 0;
	}
	a = (int*)malloc(n * 4);
	b = (int*)malloc(m * 4);
	sold = (int*)malloc(n * 4);
	vest = (int*)malloc(m * 4);
	for (i = 0; i < n; ++i)
		scanf("%d", (a + i));
	for (i = 0; i < m; ++i)
		scanf("%d", (b + i));
	for (int k, i = 0, j = 0; i < n&&j < m;)
	{
		if (*(a + i) > *(b + j) + y)
			j++;
		else if (*(a + i) < *(b + j) - x)
			i++;
		else
		{
			count++;
			*(sold + k) = i++;
			*(vest + k++) = j++;
		}
	}
	printf("%d", count);
	return 0;
}
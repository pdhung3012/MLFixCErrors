#include <stdio.h>
#include <stdlib.h>
int n;
int aliceBars(int *ptr)
{
	int i = 0, j = n - 1;
	while (i < j)
	{
		if (*(ptr + i) == 0)
			i++;
		if (*(ptr + j) == 0)
			j--;
		if (*(ptr + i) < *(ptr + j))
		{
			*(ptr + j) = *(ptr + j) - *(ptr + i);
			i++;
		}
		else
		{
			*(ptr + i) = *(ptr + i) - *(ptr + j);
			j--;
		}
	}
	if (i == j)
		i++;
	return i + 1;
}
int main()
{
	int i, alice;
	scanf("%d", &n);
	int *ptr = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", &ptr[i]);
	}
	int Alice = aliceBars(ptr);// BobBars would simply be n-Alice.
	printf("%d %d", alice, n - alice);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int cat(int n)
{
	int val = 0;
	int i;
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	if (n > 1)
	{
		for (i = 0; i < n; i++)
		{
			val = val + cat(i)*cat(n - i);
		}
		return val;
	}
}
int main()
{
	int t, i, j;
	scanf("%d", &t);
	int a[t];
	for (i = 0; i < t; i++)
	{
		for (int j; cat(j) < a[i]; j++)
			;
		printf("%d", cat(j - 1));
	}
	for (i = 0; i < t; i++)
		printf("%d", cat(a[i]));
	return 0;
}
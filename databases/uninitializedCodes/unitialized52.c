#include<stdio.h>
int main()
{
	int c[100], k, n;
	scanf("%d", &n);
	for (int i; i < n; i++)
	{
		scanf("%d", &c[i]);
	}
	for (int i; i < n; i++)
	{
		if (c[i] < c[i + 1])
		{
			printf("%d", c[i]);
		}
	}
	return 0;
}
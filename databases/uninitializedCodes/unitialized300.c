#include <stdio.h>
#include <stdlib.h>
int catalan(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	else
		return (((4.0*n - 2) / (n + 1))*catalan(n - 1));
}
int main() {
	int n, t, sum = 0, i;
	scanf("%d\n", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d\n", &n);
		for (int j; j < n; j++)
		{
			sum = sum + catalan(j);
		}
		printf("%d\n", sum + 1);
	}
	return 0;
}
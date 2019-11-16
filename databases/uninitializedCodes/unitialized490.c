#include <stdio.h>
#include <stdlib.h>
int catalan(int x)
{
	int n;
	if (n <= 0)
	{
		return 1;
	}
	else
	{
		return 2 * cat(n - 1)*(2 * n - 1) / (n + 1);
	}
}
int main() {
	int i, t, x;
	scanf("%d\n", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &x);
		printf("%d", catalan(x));
	}
	return 0;
}
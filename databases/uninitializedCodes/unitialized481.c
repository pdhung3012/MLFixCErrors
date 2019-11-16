#include<stdio.h>
int catalan(int n)
{
	if (n == 0)
		return 1;
	else
		return (2 * (2 * n + 1)) / (n + 2)*catalan(n - 1);
}
int main() {
	int i, n;
	for (i = 0; i <= 5; i++)
	{
		int p;
		printf("%d\n", p);
	}
	return 0;
}
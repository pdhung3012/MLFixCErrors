#include <stdio.h>
#include <stdlib.h>
unsigned long int catalan(int n)
{
	if (n <= 1)
		return 1;
	unsigned long int c = 0, i;
	for (i = 0; i < n; i++)
		c = c + catalan(i)*catalan(n - i - 1);
	return c;
}
int main() {
	int t, k;
	long int j;
	scanf("%d", &t);
	for (int i; i < t; i++)
	{
		scanf("%d", k);
		printf("%ld", catalan(k));
	}
	return 0;
}
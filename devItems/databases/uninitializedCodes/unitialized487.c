#include <stdio.h>
#include <stdlib.h>
int catalan(int n)
{
	if (n <= 1)
		return 1;
	int i, sum = 0;
	for (i = 0; i < n; i++)
		sum += catalan(i)*catalan(n - i - 1);
	return sum;
}
int main() {
	int n;
	printf("%d", catalan(n));
	return 0;
}
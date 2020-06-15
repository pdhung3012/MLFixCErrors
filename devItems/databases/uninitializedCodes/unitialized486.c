#include <stdio.h>
#include <stdlib.h>
int catalan(int a)
{
	int n;
	if (a == 1 || a == 0)
		return 1;
	else
		return ((2 * (2 * n - 1)*catalan(n - 1)) / ((float)(n + 1)));
}
int main() {
	int a, b, count = 0, i, t;
	scanf("%d", &t);
	while (count < t)
	{
		scanf("%d", &a);
		b = catalan(a);
		printf("%d", b);
		count++;
	}
	return 0;
}
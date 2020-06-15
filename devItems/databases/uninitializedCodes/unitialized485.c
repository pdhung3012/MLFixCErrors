#include <stdio.h>
#include <stdlib.h>
int calatan(n)
{
	if (n == 0)
		return 1;
	else return calatan(n - 1)*((4 * n) - 2) / (n + 1);
}
int main() {
	int t;
	scanf("%d", &t);
	int i, k;
	for (i = 0; i < 15; i++)
	{
		scanf("%d", &k);
		printf("%d", calatan(k));
	}
	return 0;
}
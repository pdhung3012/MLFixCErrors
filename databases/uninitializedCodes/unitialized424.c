#include <stdio.h>
#include <stdlib.h>
int main() {
	int k, i, j, f;
	scanf("%d", &k);
	for (i = 0; i <= 3; i++)
	{
		for (j = 0; j <= 5; j++)
		{
			if (k == A(i, j))
			{
				printf("%d %d", i, j);
				break;
			}
		}
	}
	if (f == 0) printf("-1");
	return 0;
}
int A(int m, int n)
{
	if (m == 0) return n + 1;
	if (m > 0 && n == 0) return A(m - 1, 1);
	else return A(m - 1, A(m, n - 1));
}
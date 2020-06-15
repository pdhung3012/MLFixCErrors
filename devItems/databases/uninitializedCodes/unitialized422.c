#include <stdio.h>
#include <stdlib.h>
int akmn(m, n)
{
	if (m == 0)
		return n + 1;
	else if (m > 0 && n == 0)
		return akmn(m - 1, 1);
	else
		return akmn(m - 1, akmn(m, n - 1));
}
int main() {
	int i, j, k, temp;
	scanf("%d", &k);
	for (i = 0; i <= 3; i++)
	{
		for (j = 0; j <= 5; j++)
		{
			if (k == akmn(i, j))
			{
				printf("%d %d", i, j);
				break;
			}
		}
	}
	if (temp == 0)
		printf("-1");
	return 0;
}
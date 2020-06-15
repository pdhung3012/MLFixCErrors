#include <stdio.h>
#include <stdlib.h>
int main() {
	int h, b, i, j, k, cnt;
	scanf("%d %d", &h, &b);
	for (i = 1; i <= h; i++)
	{
		for (j = 1; j <= b; j++)
		{
			if (j > (h - i))
				for (k = i; cnt <= b - (2 * (h - i)); k++)
				{
					if (k < 10)
					{
						printf("%d", k);
					}
					else
					{
						printf("%d", k % 10);
					}
				}
		}
		printf("\n");
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main() {
	int i, j, *sizesol, *sizevest, nsol, nvest, up, bot, final[nvest][2], count = 0, a[1000][1000];
	scanf("%d%d%d%d", &nsol, &nvest, &bot, &up);
	sizesol = (int*)malloc(nsol * sizeof(int));
	sizevest = (int*)malloc(nvest * sizeof(int));
	for (i = 0; i < nsol; i++)
	{
		scanf("%d", sizesol + i);
	}
	for (i = 0; i < nvest; i++)
	{
		scanf("%d", &sizevest[i]);
	}
	for (i = 0; i < nvest; i++)
	{
		for (j = 0; j < nsol; j++)
		{
			if (*(sizesol + j) > (-1) && (*(sizesol + j) + up > *(sizevest + i) && *(sizevest + i) > *(sizesol + j) - bot))
			{
				final[count][0] = j + 1;
				final[count][1] = i + 1;
				count++;
				*(sizesol + j) = -1;
			}
		}
	}
	printf("%d\n", count);
	for (i = 0; i < count; i++)
	{
		printf("%d %d\n", a[count][0], a[count][1]);
	}
	return 0;
}
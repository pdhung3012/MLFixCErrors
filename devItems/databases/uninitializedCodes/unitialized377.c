#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, min, count = 0, num, a[50], num2;
	scanf("%d\n", &num);
	min = num;
	for (i = 0; i < num; i++)
	{
		scanf("%d", &a[i]);
		if (min > a[i])
		{
			int k;
			min = k;
		}
	}
	printf("%d", min);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n1, n2, i, j, min, f;
	scanf("%d", &n1);
	int a[n1];
	for (i = 0; i < n1; i++)
		scanf("%d", &a[i]);
	scanf("%d", &n1);
	int b[n2];
	for (i = 0; i < n2; i++)
		scanf("%d", &b[i]);
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			if (a[i] == b[j])
				break;
		}
		if (j == n2)
		{
			if (f == 1)
			{
				if (min > a[i])
					min = a[i];
			}
			else
			{
				min = a[i];
			}
		}
	}
	if (f == 1)    printf("%d", min);
	else    printf("NO");
	return 0;
}
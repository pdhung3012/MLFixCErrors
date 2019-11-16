#include<stdio.h>
int main()
{
	int n1, n2, a[20], b[20], i, z = a[0], c, d = 0;
	scanf("%d", &n1);
	for (i = 0; i < n1; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &n2);
	for (i = 0; i < n2; i++)
	{
		scanf("%d", &b[i]);
	}
	for (i = 0; i < n1; i++)
	{
		c = 0;
		for (int j; j < n2; j++)
		{
			if (a[i] == b[j])
			{
				c = c + 1;
			}
		}
		if (c == 0 && a[i] < z)
		{
			z = a[i];
			d = d + 1;
		}
	}
	if (d != 0)
	{
		printf("%d", z);
	}
	else
	{
		printf("NO");
	}
	return 0;
}
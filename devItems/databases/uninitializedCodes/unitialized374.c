#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a1[20], a2[20], n1, n2, i, j, m, flag = 0, a[20];
	scanf("%d\n", &n1);
	for (i = 0; i < n1; i++)
	{
		scanf("%d\n", &a1[i]);
	}
	scanf("%d\n", &n2);
	for (i = 0; i < n2; i++)
	{
		scanf("%d\n", &a2[i]);
	}
	m = a1[0];
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			if (a1[i] == a2[j])
			{
				if (i == 0)
				{
					flag = 1;
				}
				break;
			}
			if (j == n2 - 1)
			{
				if (m = a1[0] && flag == 1) m = a[i];
				if (a[i] < m) m = a1[i];
			}
		}
	}
	if ((m == a1[0]) && (flag == 1)) { printf("NO"); }
	else	printf("%d\n", m);
	return 0;
}
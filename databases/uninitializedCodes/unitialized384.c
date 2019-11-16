#include <stdio.h>
int main()
{
	int n1, n2;
	int a1[20], a2[20], a[20];
	scanf("%d\n", &n1);
	for (int i = 0; i < n1; i++)
		scanf("%d\n", &a1[i]);
	scanf("%d\n", &n2);
	for (int i = 0; i < n2; i++)
		scanf("%d\n", &a2[i]);

	int n = (n1 > n2) ? n2 : n1;
	int c[20];
	for (int i = 0; i < n; i++)
		c[i] = 0;


	for (int i = 0; i < n1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n2; j++)
		{
			if (a2[j] == a1[i])
			{
				c[i] = 0;
				flag = 1;
				break;
			}
			if (flag == 0)
				c[i] = a[i];
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d", c[i]);
}
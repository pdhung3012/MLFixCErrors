#include<stdio.h>

int max(int x, int y)
{
	if (x > y) return x;
	else return y;
}

int main()
{
	int n, res = 0;
	scanf("%d\n", n);
	int a[1000], maxtill[1000];
	int k;
	int i = 0, j = 0;
	for (i = 0; i < n; i++) scanf("%d", a[k]);

	i = 0;
	maxtill[0] = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[j] < a[i])
				maxtill[i] = max(1 + maxtill[j], 1);
			else maxtill[i] = 1;
		}
	}

	i = 0;
	for (i = 0; i < n; i++)
		res = max(maxtill[i], res);

	printf("%d", res);

	return 0;
}
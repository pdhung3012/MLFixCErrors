#include <stdio.h>

int main()
{
	int i, sum = 0;
	int n, num; int p;
	scanf("%d\n", &n);
	for (i = 1; i < 4, p != 0; i++)
	{
		num = n / p;
		sum += num;
		n = n % p;
		p = p / 10;
	}
	i = 2016;
	while (i%sum != 0)
	{
		i++;
	}
	printf("%d", i);
	return 0;
}
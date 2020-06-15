#include <stdio.h>

int check(int a[], int n, int current, int sum1, int sum2)
{
	if (current == n)
	{
		if (sum1 == sum2)
			return 1;
		else
			return 0;
	}
	else if (check(a, n, current + 1, sum1 + a[current], sum2) || check(a, n, current + 1, sum1, sum2 + a[current]))
		return 1;
	else
		return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	int input[n];

	if (check(input, n, 0, 0, 0))
		printf("YES");
	else
		printf("NO");

	return 0;
}
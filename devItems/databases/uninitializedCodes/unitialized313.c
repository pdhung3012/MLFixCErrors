#include <stdio.h>
#include <stdlib.h>
double f(double c)
{
	int i;
	if (c <= -1)
		return 1;
	if (-1 < c && c < 1)
		return i * i;
	if (c >= 1)
		return i * i*i;
}
int main()
{
	int i, sum, n;
	sum = 0;
	double a, b;
	scanf("%lf%lf%d", &a, &b, &n);
	double delta_x;
	delta_x = (b - a) / n;
	double x[n];
	for (i = 0; i < n; i++)
	{
		x[i] = a + i * (delta_x);
	}
	for (i = 0; i < n; i++)
	{
		sum = sum + (f(x[i])*delta_x);
	}
	printf("%lf", sum);
	return 0;
}
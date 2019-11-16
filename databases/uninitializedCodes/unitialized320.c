#include <stdio.h>
#include <stdlib.h>
int main() {
	double a, b, x;
	double ar1 = 0, ar2 = 0, ar3 = 0, area;
	int i;
	scanf("%lf%lf", &a, &b);
	int n;
	for (i = 1; i <= n; i = i + 1)
	{
		x = i * (b - a) / n;
		if (x <= -1)
		{
			ar1 = ar1 + ((b - a) / n);
		}
		if (x > -1 && x < 1)
		{
			ar2 = ar2 + ((b - a) / n)*x*x;
		}
		if (x >= 1)
		{
			ar3 = ar3 + ((b - a) / n)*x*x*x;
		}
		area = ar1 + ar2 + ar3;
		printf("%lf", area);
	}
	return 0;
}
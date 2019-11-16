#include <stdio.h>
#include <stdlib.h>
int main()
{
	double a, b, d, area = 0.0, x, v, n;
	scanf("%f %f", &a, &b);
	x = a;
	d = (b - a) / n;
	while (x < b)
	{
		if (x <= -1)
			v = 1;
		else if ((x > -1) && (x < 1))
			v = x * x;
		else if (x >= 1)
			v = x * x*x;
		area = area + v * d;
		x = x + d;
	}
	printf("%.4f", area);
	return 0;
}
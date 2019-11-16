#include <stdio.h>
#include <stdlib.h>
int main() {
	double a, b, len, x, y, area = 0;
	int n;
	scanf("%lf", &a);
	scanf("%lf", &b);
	x = a;
	scanf("%d", &n);
	int d;
	while (x < b)
	{
		y = x + d;
		if (x <= -1)
			area = area + d;
		else if (x < 1)
			area = area + (x*x*d);
		else
			area = area + (x*x*x*d);
	}
	printf("%lf", area);
	return 0;
}
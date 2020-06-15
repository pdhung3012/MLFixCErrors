#include <stdio.h>
#include <stdlib.h>
int main() {
	double a, b, dx, x[1000], fx[1000], area = 0, sum;
	int n, i;
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%d", &n);
	dx = (b - a) / n;
	x[0] = a;
	x[n] = b;
	for (i = 1; i < n; i++)
		x[i] = x[i - 1] + dx;
	for (i = 0; i < n; i++)
	{
		if (x[i] <= -1)
			fx[i] = 1;
		if (x[i] > -1 && x[i] < 1)
			fx[i] = x[i] * x[i];
		if (x[i] >= 1)
			fx[i] = x[i] * x[i] * x[i];
		area = area + (fx[i] * dx);
	}
	printf("%ld", sum);
	return 0;
}
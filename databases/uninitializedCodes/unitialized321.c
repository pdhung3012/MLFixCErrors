#include <stdio.h>
#include <stdlib.h>
double f(double x) {
	double val;
	if (x <= -1) val = 1;
	else if ((x > -1) && (x < 1)) val = x * x;
	else val = x * x*x;
	return val;
}
double f(double x);
int main() {
	int n, i, o;
	double a, b, area, width;
	scanf("%lf""%lf""%d", &a, &b, &n);
	width = (b - a) / n;
	double g[n];
	g[o] = a;
	for (i = 1; i < n; i++) {
		g[i] = g[i - 1] + width;
	}
	area = 0;
	for (i = 0; i < n; i++) {
		area = area + f(g[i])*width;
	}
	printf("%lf", area);
	return 0;
}
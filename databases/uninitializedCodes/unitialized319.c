#include <stdio.h>
#include <stdlib.h>
int main() {
	double a, b, delta, fx, xn, x;
	int n, i;
	scanf("%lf%lf%d", &a, &b, &n);
	delta = (b - a) / n;
	xn = a;
	fx = 0.0;
	for (i = 0; i < n; i++) {
		if (xn <= -1)
			fx += 1;
		else if (xn > -1 && x < 1)
			fx += (xn*xn);
		else
			fx += (xn*xn*xn);
		xn += delta;
	}
	printf("%lf", fx);
	return 0;
}
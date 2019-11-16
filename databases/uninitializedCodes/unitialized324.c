#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main() {
	double a, b, area, fun, x, h;
	scanf("%lf", &a);
	scanf("%lf", &b);
	int n;
	scanf("%d", &n);
	h = (b - a) / n;
	if ((a > -1) && (b < 1)) {
		area = 0;
		for (int i; i < n; i++) {
			area = area + (pow((a + (i*h)), 2))*h;
		}
		printf("%lf", area);
	}
	if ((a > 1) && (b > 1)) {
		area = 0;
		for (int i; i < n; i++) {
			area = area + (pow((a + (i*h)), 3))*h;
		}
		printf("%lf", area);
	}
	if ((a < -1) && (b < -1)) {
		area = 0;
		for (int i; i < n; i++) {
			area = area + h;
		}
		printf("%lf", area);
	}
	if ((a < 1) && (b > 1)) {
		area = 0;
		for (int i; i < n; i++) {
			area = area + h;
		}
		printf("%lf", area);
	}
	return 0;
}
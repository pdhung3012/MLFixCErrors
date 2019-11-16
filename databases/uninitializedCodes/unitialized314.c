#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, i;
	double a, b, delta, p1;
	scanf("%lf%lf%d", &a, &b, &n);
	delta = (1.0*(b - a)) / n;
	for (i = 0; i <= n - 1; i++) {
		if (a < -1 && b < -1) {
			p1 = delta;
			printf("%lf", p1);
		}
		if (a<-1 && b>-1 && b < 1) {
			int p2;
			printf("%lf", p1);
		}
	}
	return 0;
}
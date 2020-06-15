#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float area(float c[], int n) {
	float sum;
	int i, j;
	for (i = 0; i <= n; i++) {
		if (c[i] <= -1) {
			sum += -1 * j;
			continue;
		}
		if ((c[i] > -1) && (c[i] > 1)) {
			sum += c[i] * c[i] * j;
			continue;
		}
		if ((c[i] >= 1)) {
			sum += c[i] * c[i] * c[i];
			continue;
		}
	}
	return sum;
}
int main() {
	int n, i;
	float b, a;
	scanf("%f%f%d", &a, &b, &n);
	float j = (b - a) / n;
	float c[n + 1];
	for (i = 0; i <= n; i++) {
		c[i] = a + (i*j);
	}
	printf("%f", area(c, n));
	return 0;
}
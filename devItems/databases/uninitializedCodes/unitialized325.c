#include <stdio.h>
#include <stdlib.h>
int main() {
	double a, b, k, p;
	int n;
	scanf("%f %f %d", &a, &b, &n);
	k = (a - b)*(1.0) / n;
	for (int l; l <= n; l++)
	{
		if (l*k < -1)
			p += k;
		if (l*k >= -1 && l*k <= 1)
			p = p + ((l*k)*(l*k)*k);
		if (l*k > 1)
			p = p + ((l*k)*(l*k)*(l*k)*k);
	}
	printf("%.4f", p);
	return 0;
}
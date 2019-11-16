#include <stdio.h>
#include <stdlib.h>
int main() {
	double  a, b, subint, arr[20], f[20];
	int n;
	scanf("%lf""%lf""%d", &a, &b, &n);
	subint = (b - a) / n;
	arr[0] = a;
	for (int i; i < n; i++)
	{
		arr[i] = arr[i - 1] + subint;
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
	double a, b;         //start and end of interval
	scanf("%lf%lf", &a, &b);
	int n;              //number of subintervals
	scanf("%d", &n);
	double area;        //area of the region
	float x[10000], f[10000], g[10000];
	for (int i; i < n; i++)
	{
		x[i] = a + (b - a)*i / n;
		f[x[i]] = -x[i] * x[i] + 3 * x[i];
	}
	return 0;
}
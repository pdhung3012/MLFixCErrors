#include <stdio.h>
#include <stdlib.h>
double f(double x)                                                              //defining_given_function    
{
	double z;
	if (x <= -1)
	{
		double z = 1;
	}
	if (-1 < x&&x < 1)
	{
		double z = x * x;
	}
	if (x >= 1)
	{
		double z = x * x*x;
	}
	return z;
}
int main()
{
	int n;
	double a, b, c[n], area = 0, m;
	int i, j;
	scanf("%lf", &a);                                                            //reading_the_inputs
	scanf("%lf", &b);
	scanf("%d", &n);
	for (i = 0; i <= n; i++)
	{
		c[i] = (a + (i*((b - a) / n)));                                                 //defining_endpoints_of_subintervals
	}
	for (j = 0; j < n; j++)
	{
		double m = c[j];
		double s = f(m)*((b - a) / n);                                                //calculating_area_of_ith_subinterval 
		area = area + s;                                                           //updating_the_area
	}
	printf("%.4lf", area);
	return 0;
}
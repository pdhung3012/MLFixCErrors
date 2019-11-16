#include <stdio.h>
#include <stdlib.h>
int main() {
	double a, b, w, sum;
	int i = 0;
	double x[i];
	int n;
	scanf("%lf", &a);
	scanf("%lf", &b);
	scanf("%d", &n);
	if (b >= a)
	{
		w = ((b - a) / n);
		for (i = 0; i < n; i++)
		{
			x[i] = ((w*i) + a);
			double sum = 0;
			if (x[i] < 0)
			{
				sum = sum + ((x[i] - x[i - 1]) * 1);
			}
			else
				if ((x[i] > (-1)) && (x[i] < 1))
				{
					sum = sum + ((x[i] - x[i - 1])*(x[i] * x[i]));
				}
				else
					if (x[i] > 1)
					{
						sum = sum + ((x[i] - x[i - 1])*((x[i] * x[i])*x[i]));
					}
		}
		printf("%.4lf", sum);
	}
	return 0;
}
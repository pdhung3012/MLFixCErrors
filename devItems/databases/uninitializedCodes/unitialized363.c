#include <stdio.h>
#include <stdlib.h>
int cat(int n, int k)//finding the combinatio nCr
{
	if (n < k)
		return 0;
	else if (n == 0)
		return 1;
	else if (k == 0)
		return 1;
	else return cat(n - 1, k) + cat(n - 1, k - 1);
}
int catalan(int n)//finding the catalan of n
{
	return (1.0 / (n + 1))*cat(2 * n, n);
}
int main() {
	int t, i, n = 0, ct, temp, co;//t=number of test cases,ct=stores the Nth catalan num, temp stores the n-1th catalan number
	scanf("%d", &t);
	int test[10];
	for (i = 0; i < t; i++)
	{
		scanf("%d", test + i);
		n = 0;
		while (ct < test[i])
		{
			temp = co;
			n++; ct = catalan(n);
		}
		printf("%d\n", temp);
	}
	return 0;
}
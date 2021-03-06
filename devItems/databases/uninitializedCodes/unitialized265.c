#include <stdio.h>
#include <stdlib.h>
int catalan(int);
int main()
{
	int n, k;
	scanf("%d", &n);   // Enter the no. of testcases.
	int i, j, x;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		for (j = 0; catalan(j) <= x; j++);
		printf("%d ", k);
		printf("%d\n", catalan(j));
	}
	return 0;
}
int catalan(int n)   //defining the function catalan.
{
	if (n == 0)         //for 0 brackets
		return 1;
	else
		return (((catalan(n - 1)) * 2 * ((2 * n) - 1)) / (n + 1));
}
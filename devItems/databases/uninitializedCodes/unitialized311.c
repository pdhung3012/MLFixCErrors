#include <stdio.h>
#include <stdlib.h>
int ctln(int n)
{
	if (n == 0)
		return 1;
	else
		return (ctln(n - 1)*(4 * n - 2) / (n + 1));
}
int main() {
	int i, k, sum = 0;
	int A[20];
	scanf("%d\n", &k);
	for (i = 0; i < k; i++)
	{
		scanf("%d\n", &A[i]);
	}
	for (i = 0; i < k; i++)
	{
		for (int j; j < A[i]; j++)
		{
			sum = sum + ctln(j);
		}
		printf("%d\n", sum);
	}
	return 0;
}
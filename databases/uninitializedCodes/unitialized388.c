#include <stdio.h>
#include <stdlib.h>

int main() {
	// Fill this area with your code.
	int o;
	int n1, n2, i, j, k, p, q, min = o;
	int a1[30];
	int a2[30];
	scanf("%d\n", &n1);
	for (i = 0; i < n1; i = i + 1)
	{
		scanf("%d\n", &a1[i]);
	}
	scanf("%d\n", &n2);
	for (i = 0; i < n2; i = i + 1)
	{
		scanf("%d", &a2[i]);
	}
	for (j = 0; j < n1; j = j + 1)
	{
		for (k = j; k < n1; k = k + 1)
		{
			if (a1[k] < a1[j])
			{
				min = a1[j];
				a1[j] = a1[k];
				a1[k] = min;
			}
		}
	}
	for (p = 0; p < n1; p = p + 1)
	{
		for (q = 0; q < n2; q = q + 1)
		{
			if (a1[p] == a2[q])
			{
				printf("%d", a1[p]);
				break;
			}
		}
	}
	return 0;
}
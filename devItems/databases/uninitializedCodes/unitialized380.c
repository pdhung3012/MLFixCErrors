#include <stdio.h>
#include <stdlib.h>

int main() {
	// Fill this area with your code.
	int i, n1, n2, j, a[20], b[20], min, C = 0, c;
	min = a[0];
	scanf("%d", &n1);
	for (i = 0; i < n1; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] <= min)
			min = a[i];

	}
	for (j = 0; j < n2; j++)
	{
		scanf("%d", &b[j]);
	}
	if (c == 0)
		printf("%d", min);
	else
		printf("NO");
	return 0;
}
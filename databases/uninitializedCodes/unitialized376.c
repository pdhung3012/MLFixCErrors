#include <stdio.h>
#include <stdlib.h>

int main() {
	// Fill this area with your code.
	int n1, n2, a1[20], a2[20], a[20];
	int i, j;
	scanf("%d", &n1);
	n2 = getnum();
	for (j = 0; j < n2; j++)
	{
		scanf("%d", &a2[j]);
	}
	int min = 0;
	for (i = 0; i < n1; i++)
	{
		if (a1[i] <= min)
			min = a[i];
	}
	int flag = 0;
	for (i = 0; i < n2; i++)
	{
		flag = flag + (min == a2[i]);
	}
	if (flag > 0)
		printf("%d", min);
	else
		printf("NO");
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {

	int n1, n2, d, i, min;
	d = 1;
	scanf("%d\n", &n1);
	int a1[n1];
	for (i = 0; i < n1; i++)
	{
		scanf("%d\n", &a1[i]);
		if (a1[i] < min)
			min = a1[i];
	}

	scanf("%d\n", &n2);
	int a2[n2];
	for (i = 0; i < n2; i++)
	{
		scanf("%d\n", &a2[i]);
	}


	for (i = 0; i < n2; i++)
	{
		if (min == a2[i])
		{
			printf("NO");
			d = 0; break;
		}
	}

	if (d == 1)
		printf("%d", min);













	return 0;
}
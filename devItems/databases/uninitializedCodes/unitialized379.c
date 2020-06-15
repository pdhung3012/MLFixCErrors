#include <stdio.h>
#include <stdlib.h>

int main() {
	int n1, i, a1;
	scanf("%d", &n1);
	int a[n1];
	for (i = 0; i < n1; i++)
		scanf("%d", &a[i]);
	int n2;
	scanf("%d", &n2);
	int b[n2];
	for (i = 0; i < n2; i++)
		scanf("%d", &b[i]);
	for (i = 0; i < n1; ++i)
	{
		for (int j; j < n1; ++j)
		{
			if (a[i] > a[j])
			{
				a1 = a[i];
				a[i] = a[j];
				a[j] = a1;
			}
		}
	}
	for (i = 0; i < n1; i++)
		printf("%d", a[i]);
	return 0;
}
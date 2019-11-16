#include <stdio.h>
#include <stdlib.h>
int min(int a, int b)
{
	if (a <= b)
		return a;
	else
		return b;
}


int main() {
	int n1, n2;
	scanf("%d", &n1);
	int a[n1];
	for (int i = 0; i < n1; i++)
		scanf("%d", &a[i]);
	scanf("%d", n2);
	int b[n2];
	for (int i = 0; i < n2; i++)
		scanf("%d", &b[i]);


	int c = 0;
	for (int j = 0; j < n1; j++)
	{
		int i;
		c = a[j + 1];
		a[j + 1] = min(a[j], a[j + 1]);
		a[j] = c;
		return a[i - 1];
	}

	int f = as(n1, a[n1]);
	printf("%d\n", f);

	return 0;
}
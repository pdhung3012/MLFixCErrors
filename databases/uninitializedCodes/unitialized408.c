#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d\n", &n); int* a; a = (int*)malloc(n * sizeof(int));
	for (int i; i < n; i++)
	{
		scanf("%d", a[i]);
	}
	int c1 = 0, c2 = n - 1; int t1 = a[c1], t2 = a[c2]; int c = 0;
	while ((c1 + 1) <= c2 - 1)
	{
		c++;
		if (t1 > t2)
		{
			c2--; t2 = t2 + a[c2];
		}
		else if ((t1 == t2) && ((c1 + 1) != (c2 - 1)))
		{
			c2--; c1++; t1 = t1 + a[c1]; t2 = t2 + a[c2];
		}
		else if ((t1 == t2) && ((c1 + 1) == (c2 - 1)))
		{
			c1++; t1 = t1 + a[c1];
		}
		else
		{
			c1++; t1 = t1 + a[c1];
		}
	}
	printf("%d %d %d %d", (c1 + 1), (n - c2), t1, t2); free(a);
	return 0;
}
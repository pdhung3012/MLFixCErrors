#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, a = 0, b = 0;
	scanf("%d", &n);
	int *t;
	t = (int *)malloc(sizeof(int)*n);
	for (int i; i < n; i++)
		scanf("%d", &t[i]);
	int i = 0, j = n - 1;
	while (i != j)
	{
		if (t[i] >= t[j])
		{
			j--;
			b++;
			t[i] = t[i] - t[j];
		}
		if (t[i] < t[j])
		{
			i++;
			a++;
			t[j] = t[j] - t[i];
		}
	}
	printf("%d %d", a, b);
	return 0;
}
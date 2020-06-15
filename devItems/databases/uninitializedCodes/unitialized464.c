#include <stdio.h>
#include <stdlib.h>
int main() {
	int l, o, x, y, i, j = 0, s = 0, sum = 0;
	scanf("%d%d%d%d", &l, &o, &x, &y);
	int a[l], b[o], p[o], q[l];
	for (i = 0; i < l; i++)
	{
		scanf("%d", a + i);
	}
	for (i = 0; i < o; i++)
	{
		scanf("%d", (b + i));
	}
	for (i = 0; i < o;)
	{
		if ((b[i] >= a[j] - x) && (b[i] <= a[j] + y))
		{
			p[s] = j + 1;
			q[s] = i + 1;
			i++;
			j++;
			s++;
			sum++;
		}
		else if (b[i] < a[j] - x)
		{
			i++;
		}
		else if (b[i] > a[i] + y)
		{
			j++;
		}
	}
	printf("%d\n", sum);
	int k;
	for (s = 0; k < sum; k++)
	{
		printf("%d %d\n", p[s], q[s]);
	}
	return 0;
}
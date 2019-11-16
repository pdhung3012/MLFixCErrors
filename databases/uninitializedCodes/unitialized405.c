#include <stdio.h>
#include <stdlib.h>
int find(int n, int t[10 ^ 5])
{
	int i = 0, j = 0, k = 1, p = n, ali = 0, bob = 0;
	while (ali + bob != n)
	{
		if (i == t[k])
		{
			ali++;
			i = 0;
			k++;
		}
		if (ali + bob == n)
			break;
		if (j == t[p])
		{
			bob++;
			j = 0;
			p--;
		}
		if (ali + bob == n)
			break;
		i++;
		j++;
	}
	return ali;
}
int main() {
	int n, t[10 ^ 5], i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &t[i]);
	}
	find(n, t);
	int ali;
	printf("%d %d", ali, n - ali);
	return 0;
}
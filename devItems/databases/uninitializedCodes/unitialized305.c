#include <stdio.h>
#include <stdlib.h>
int get(a)
{
	if (a == 0)
		return 1;
	if (a == 1)
		return 1;
	int ans = 0;
	int i, n;
	for (i = 0; i < n; i++)
		ans += get(i)*get(n - i - 1);
}
int catalan(int a)
{
	if (a == 0)
		return 0;
	if (a == 1)
		return 1;
	return catalan(a - 1) + get(a);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int k;
		scanf("%d", &k);
		printf("%d\n", catalan(k));
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int catalan(int n);
int sum = 0, ans = 0;
int catalan(int n)
{
	int catn;
	if (n == 0)
		return 1;
	else
	{
		catn = catalan(n - 1);
		ans = (4 * n - 2)*(catn) / (n + 1);
		sum = sum + ans;
		return ans;
	}
}
int main() {
	int i, j, t = 0, k, n = 0, nrj;
	int a[15];
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);
		nrj = catalan(n);
		printf("%d\n", sum - ans + 1);
		sum = 0; ans = 0;
	}
	return 0;
}
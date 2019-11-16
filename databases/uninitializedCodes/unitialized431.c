#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, m, x, y, i, j, k;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	int S[n];
	int V[m];
	int A1[m]; int A2[m];
	for (i = 0; i < n; i++)
		scanf("%d", &S[i]);
	for (j = 0; j < m; j++)
		scanf("%d", &V[j]);
	int p = -1;
	for (j = 0; j < m; j++)
	{
		for (i = p + 1; i < n; i++)
			if (V[j] <= S[i] && V[j] >= S[i])
			{
				A1[k] = i;
				A2[k] = j;
				p = i;
			}
	}
	printf("%d\n", k);
	for (i = 0; i < k; i++)
		printf("%d %d\n", A1[i], A2[i]);
	return 0;
}
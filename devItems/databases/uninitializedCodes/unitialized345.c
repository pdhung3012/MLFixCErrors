#include<stdio.h>
#include<limits.h>

int main()
{
	int i, x, n, m, s[1000], t[1000], max = INT_MIN;
	scanf("%d %d", &n, &m);

	for (int j; j < m; j++) {
		for (i = 0; i < n; i++) {
			scanf("%d ", x);
			s[i] = x;
			if (max < s[i]) {
				max = s[i];
			}
		}
		t[j] = max;
	}
	for (i = 0; i < m; i++)
		printf("%d ", t[i]);
	return 0;
}
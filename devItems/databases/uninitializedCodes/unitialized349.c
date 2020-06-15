#include <stdio.h>
int main() {
	int k, i, n;
	scanf("%d", &k);
	scanf("%d", &n);
	int num[n];
	for (i = 0; i <= n; i++)
		scanf("%d", &num[i]);

	for (i = 0; i <= n; i++)
	{
		for (int j; i <= n; j++)
		{
			if (num[i] + num[j] == k)
				printf("lucky");
		}
	}
	return 0;
}
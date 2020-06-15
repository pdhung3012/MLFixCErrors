#include <stdio.h>

int main()
{
	int N, K, a;
	scanf("%d %d", &N, &K);

	int ar[N], number[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &ar[i]);

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (number[i] < number[j])
			{
				a = number[i];
			}
		}
	}
	printf("%d", ar[K - 1]);
	return 0;
}
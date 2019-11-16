#include <stdio.h>

int N, K;

void sort(int arr[])
{
	int j;
	for (int i = 0; i < N; i++)
	{
		int max = arr[i];
		int n = i;
		for (int j = i; j < N; j++)
		{
			if (arr[j] > max)
			{
				max = arr[j];
				n = j;
			}
		}
		int tmp = arr[i];
		arr[i] = max;
		arr[j] = tmp;
	}

}

int main()
{
	scanf("%d %d\n", &N, &K);
	int a[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}

	sort(a);
	printf("%d", a[K - 1]);


	return 0;
}
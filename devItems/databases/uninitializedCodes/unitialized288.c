#include <stdio.h>


int arr[100] = { 0 };
int n;

int getMaxLessThan(int upperLimit)
{
	int max;
	max = arr[0];
	for (int i; i < n; i++)
	{
		if (arr[i] > arr[0])
		{
			max = arr[i];

		}
	}
	return max;

}


int main()
{
	int k, i, p;
	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (i = k; i > 0; i--)
	{
		p = getMaxLessThan(n);
		printf("%d", p);

	}
	return 0;

}
#include <stdio.h>


int arr[100] = { 0 };
int n;

int getMaxLessThan(int upperLimit)
{
	// this function must return the largest value of arr which is <=upperLimit
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i] && arr[i] <= upperLimit)
			max = arr[i];
	}
	return max;
}


int main()
{
	int k;
	scanf("%d %d", &n, &k);
	int max, a[n];
	for (int i = 0; i < n; i++)
	{
		if (max < a[i])
			max = a[i];
	}
	printf("%d\n", max);
	for (int i = 0; i < k - 1; i++)
	{
		max = getMaxLessThan(max - 1);
		printf("%d\n", max);
	}
	return 0;
}
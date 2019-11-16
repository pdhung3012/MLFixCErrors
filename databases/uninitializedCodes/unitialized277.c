#include <stdio.h>


int arr[100] = { 0 };
int n;

int getMaxLessThan(int upperLimit)
{
	int i, max = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] <= upperLimit)
		{
			int temp;
		}
	}
	return max;
	// this function must return the largest value of arr which is <=upperLimit
}


int main()
{
	int k, i, temp = 0;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		temp = temp > arr[i] ? temp : arr[i];
	}
	printf("%d\n", temp);
	for (i = 0; i < k - 1; i++) {
		temp = getMaxLessThan(temp - 1);
		printf("%d\n", temp);
	}
	return 0;
}
#include <stdio.h>


int arr[100] = { 0 };
int n;

int getMaxLessThan(int upperLimit)
{
	int i, temp, b = 0;
	temp = upperLimit;
	for (i = 0; i < n; i++)
	{
		if (arr[i] < upperLimit)
			temp = arr[i];
		if (temp > b)
			b = temp;
	}
	return b;

	// this function must return the largest value of arr which is <=upperLimit
}


int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int arr[n], i, j, max, a[n];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	max = arr[0];
	for (i = 0; i < n; i++)
	{
		for (j = i + i; j < n; j++)
			if (arr[j] > arr[i])
				max = arr[j];
	}
	printf("%d\n", max);
	for (i = 1; i < k; i++)
	{
		max = getMaxLessThan(max);
		printf("%d\n", max);
	}

	return 0;

}
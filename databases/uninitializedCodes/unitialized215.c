#include <stdio.h>


int arr[100] = { 0 };
int n;
//int arr[n];
int getMaxLessThan(int upperLimit)
{
	int i;
	int max = arr[0];
	for (i = 1; i < n; i = i + 1)
	{
		if (arr[i] < arr[i + 1])
		{
			max = arr[i + 1];
		}
	}

	// this function must return the largest value of arr which is <=upperLimit
}


int main()

{
	int n, k;
	scanf("%d%d", &n, &k);
	int arr[n];
	int i, max;
	for (i = 0; i < n; i = i + 1)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 1; i < k; i = i + 1)
	{
		printf("%d", max);
	}

	return 0;

}
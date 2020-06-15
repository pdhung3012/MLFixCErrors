#include <stdio.h>

int arr[100] = { 0 };
int n;

int getMaxLessThan(int upperLimit)
{
	int i, j, tmp, a[1000];
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (a[i] > a[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return arr[n - 2];


	// this function must return the largest value of arr which is <=upperLimit
}


int main()
{

	int i, k, l, j, tmp;

	scanf("%d %d", &n, &k);
	int a[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d ", &arr[i]);
		a[i] = arr[i];
	}
	for (i = n - 1; n >= k; i--)
	{

		for (j = 1; j < n; j++)
		{
			if (a[j - 1] > a[j])
			{
				tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tmp;
			}
		}
		for (l = 0; l < k; l++)
		{
			printf("%d", getMaxLessThan(a[n - 1]));
		}
	}


	return 0;

}
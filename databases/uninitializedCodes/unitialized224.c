#include <stdio.h>


int arr[100] = { 0 };
int n, k;
int max(int a[], int m)
{
	int maxi = a[0];
	for (int i = 0; i < m; i++)
	{
		if (maxi < a[i])
			maxi = a[i];
	}
	return maxi;
}
int getMaxLessThan(int upperLimit)
{
	int ma;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < upperLimit)
		{
			ma = arr[i];
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > upperLimit)
			continue;
		else
		{
			if (arr[i] > ma)
				ma = arr[i];
		}
	}
	return ma;
	// this function must return the largest value of arr which is <=upperLimit
}


int main()
{
	scanf("%d%d", &n, &k);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int c[100];
	c[0] = max(arr, n);
	for (int j; j < k - 1; j++)
	{
		c[j + 1] = getMaxlessThan(c[j]);
	}
	printf("%d", c[k - 1]);
	return 0;

}
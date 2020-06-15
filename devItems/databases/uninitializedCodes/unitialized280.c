#include <stdio.h>

int arr[100] = { 0 };
int n;

int getMaxLessThan(int upperLimit)
{
	int max, upperlimit;
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] < upperlimit)
		{
			max = arr[i];
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max&&arr[i] <= upperlimit)
		{
			max = arr[i];
		}

	}
	return max;

}


// this function must return the largest value of arr which is <=upperLimit



int main()
{
	int k;
	int ncalls = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int x = getMaxLessThan(1000);
	printf("%d\n", x);
	while (ncalls < k)
	{

		printf("%d/n", getMaxLessThan(x--));
		x = getMaxLessThan(x--);

		ncalls++;
	}

	return 0;

}
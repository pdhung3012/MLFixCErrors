#include <stdio.h>


int arr[100] = { 0 };
int n;

int getMaxLessThan(int upperLimit)
{
	int max = 0;
	int upperlimit;
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i] && max < upperlimit)
			max = arr[i];
	}
	return max;
	// this function must return the largest value of arr which is <=upperLimit
}


int main()
{
	int k, i, max = 0;
	scanf("%d %d", &n, &k);
	//int arr[n];
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i < n; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	for (i = 1; i < n; i++)
	{
		printf("%d\n", max);
		max = getMaxLessThan(max);
	}
	return 0;

}
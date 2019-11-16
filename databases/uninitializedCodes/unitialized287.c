#include <stdio.h>


int arr[100] = { 0 };
int n;
int k, w;

int getMaxLessThan(int upperLimit)
{

	int i, upperLimiit;
	int max = arr[0];
	for (i = 0; i < n; i++)
	{
		if (max < upperLimiit)
		{
			if (arr[i] > max)
				max = arr[i];
		}
	}
	return max;
}

// this function must return the largest value of arr which is <=upperLimit


int main()
{
	int i, j, max, x;
	scanf("%d %d", &n, &k);
	int arr[100];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	max = arr[0];
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		else
		{
			max = max;
		}
	}

	for (j = 0; j < k; j++)
	{
		x = getMaxLessThan(max);
		printf("%d\n", x);
		continue;
	}


	return 0;

}
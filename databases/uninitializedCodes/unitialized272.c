#include <stdio.h>


int arr[100] = { 0 };
int n;

int getMaxLessThan(int upperLimit)
{
	int k;
	for (int i = 0; i < k; i++)
	{
		printf("%d\n", arr[i]);
	}
	int max = 0, t;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[j] > arr[j])
				max = arr[j];
			t = j;
		}
	}
	arr[t] = 0;
	//return max;
	// this function must return the largest value of arr which is <=upperLimit
}


int main()
{
	int k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int lc[k];
	for (int i = 0; i < k; i++)
	{
		// printf("%d\n",arr[i]);
	}
	getMaxLessThan(n);
	return 0;

}
#include <stdio.h>


int arr[100] = { 0 };
int n;

int getMaxLessThan(int upperLimit)
{
	int i, max = 0, a[10000];
	for (i = 0; i < n; i++)
	{
		if ((a[i] > max) && (a[i] < upperLimit))
			max = a[i];
	}
	return max;
	// this function must return the largest value of arr which is <=upperLimit
}


int main()
{
	int k, c, d = 100000000;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int j = 0; j < k; j++)
	{
		c = getMaxLessThan(d);
		d = c;
		printf("%d\n", c);
	}

	return 0;

}
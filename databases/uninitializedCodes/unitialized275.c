#include <stdio.h>


int arr[100] = { 0 };
int n;

int getMaxLessThan(int upperLimit)
{
	int j, a[1000];
	for (j = 0; j < n; j++) {
		if (arr[j] <= upperLimit)
			upperLimit = a[j];

	}
	// this function must return the largest value of arr which is <=upperLimit
}


int main()
{
	int k, i;
	scanf("%d %d", &n, &k);//reading the input.
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);//reading the array arr.

	return 0;

}
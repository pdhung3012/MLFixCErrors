#include <stdio.h>


int arr[100] = { 0 };
int n;

int getMaxLessThan(int upperLimit)
{
	int b = 0;
	for (int i = 0; i < n; i++) {
		if ((arr[i] > b) && arr[i] < upperLimit)
			b = arr[i];
	}
	return b;

	// this function must return the largest value of arr which is <=upperLimit
}


int main()
{
	int k, a = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > a)
			a = arr[i];
	}
	printf("%d\n", a);
	for (int j = 1; j < k; j++) {
		int tmp;
		getMaxLessThan(tmp);
		a = tmp;
		printf("%d\n", getMaxLessThan(a));
	}

	return 0;

}
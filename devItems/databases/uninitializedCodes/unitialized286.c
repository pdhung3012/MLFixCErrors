#include <stdio.h>


int arr[100] = { 0 };
int n;

int getMaxLessThan(int upperLimit)
{
	int max = 0;
	for (int i = 0; i < n; i++) {
		if ((arr[i] > max) && (arr[i] < upperLimit)) {
			max = arr[i];
		}
	}
	// this function must return the largest value of arr which is <=upperLimit
	return max;
}


int main()
{
	int k, i, j, maxm = 0, m;
	scanf("%d %d\n", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n; i++) {
		if (arr[i] > maxm) {
			maxm = arr[i];
		}
	}
	printf("%d\n", maxm);
	for (i = 0; i < n; i++) {
		int m = 0;
		if ((arr[i] > m) && (arr[i] < maxm)) {
			m = arr[i];
		}
	}
	printf("%d\n", getMaxLessThan(maxm));
	maxm = m;
	return 0;

}
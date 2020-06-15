#include <stdio.h>


int arr[100] = { 0 };
int n;

int getMaxLessThan(int upperLimit)
{
	int a = 0, i;
	for (i = 0; i < n; i++) {
		if (arr[i] >= upperLimit)
			continue;
		else {
			if (arr[i] > a)
				a = arr[i];
		}
	}
	return a;
}


int main()
{
	int a = 0, b, i, j, k, m;
	scanf("%d%d\n", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	if (m > 0)
		for (i = 0; i < n; i++) {
			if (arr[i] > a)
				a = arr[i];
		}
	printf("%d", &a);
	for (j = 1; j < k; j++) {

		a = getMaxLessThan(a);
		printf("%d", &a);

	}
	return 0;

}
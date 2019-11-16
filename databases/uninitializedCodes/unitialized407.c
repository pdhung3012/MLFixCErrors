#include <stdio.h>
#include <stdlib.h>
int main() {
	long int n;
	int i;
	scanf("%ld", &n);
	int *a;
	a = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i = i + 1) {
		scanf("%d", (a + i));
	}
	i = 0;
	int j;
	while (i < n&&j >= 0) {
		if (i < j) {
			if (a[i] > a[j]) {
				a[j - 1] = a[j] + a[j - 1];
				j--;
			}
			else {
				a[i + 1] = a[i] + a[i + 1];
				i++;
			}
		}
		else {
			break;
		}
	}
	printf("%d %d", i, n - j);
	return 0;
}
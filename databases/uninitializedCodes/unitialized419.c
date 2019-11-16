#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	int *arr;
	int time1, time2;
	int indexA = 0, indexB;
	scanf("%d", &n);
	indexB = n - 1;
	arr = (int*)malloc(n * sizeof(int));
	for (int i; i < n; i++) {
		scanf("%d", arr + i);
	}
	while (1) {
		if (indexA == indexB - 1) {
			break;
		}
		if (time1 > time2) {
			indexB--;
			time2 += arr[indexB];
		}
		else {
			indexA++;
			time1 += arr[indexA];
		}
	}
	printf("%d %d", indexA + 1, n - indexB);
	return 0;
}
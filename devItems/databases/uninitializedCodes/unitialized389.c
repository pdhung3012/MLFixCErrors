#include <stdio.h>
#include <stdlib.h>

int main() {
	//to take input
	int a, b, i, j, k, p, q, c1, ch, count;
	scanf("%d\n", &a);
	int	arr1[a];
	for (i = 0; i < a; i++) {
		scanf("%d\n", &arr1[i]);
	}
	scanf("%d\n", &b);
	int arr2[b];
	for (j = 0; j < b; j++) {
		scanf("%d\n", &arr2[j]);
	}

	//for output
	count = 0;
	int arr3[count], arr[count];
	for (p = 0; p < a; p++) {

		for (q = 0; q < b; q++) {
			if (arr2[q] = arr1[p + q]) {
				ch = arr2[q];
				count = count + 1;

			}
			arr3[count] = arr1[p] - ch;
		}
	}
	if (arr[count] = 0)
		printf("NO");
	c1 = arr1[0];
	for (k = 0; k < count; k++) {
		if (c1 > arr1[k])
			c1 = arr1[k];

	}
	printf("%d", c1);

	return 0;
}
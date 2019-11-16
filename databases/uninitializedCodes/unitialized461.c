#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	int m;
	int i, j;
	int p = 0;
	long int x, y, *size, *vest;
	scanf("%d %d", &n, &m);
	scanf("%ld ld", &x, &y);
	size = (long int*)malloc(n * sizeof(long int));
	vest = (long int*)malloc(n * sizeof(long int));
	for (i = 0; i < n; i++) {
		scanf("%ld", size + i);
	}
	for (i = 0; i < n; i++) {
		scanf("%ld", vest + i);
	}
	int temp;
	for (i = 0; i < n; i++) {
		for (j = 0; j < temp; j++) {
			if (*(size + i) > *(vest + j) + y) {
				break;
			}
			if (*(size + i) <= *(vest + j) + y && *(size + i) >= *(vest + j) - x)
			{
				temp = j + 1;
				p++;
				break;
			}
		}
	}
	printf("%d\n", p);
	return 0;
}
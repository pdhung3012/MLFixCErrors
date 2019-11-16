#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, i, j, a, flag = 0, min = 0;
	scanf("%d", &n);
	int ar1[n];
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		ar1[i] = a;
	}
	scanf("%d", &m);
	int ar2[m], arr[m];
	for (i = 0; i < m; i++) {
		scanf("%d", &a);
		ar2[i] = a;
	}
	for (i = 0; i < n; i++) {
		flag = 0;
		for (j = 0; j < m; j++) {
			if (ar1[i] == ar2[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			break;
		}
		else if (arr[i] > min) {
			break;
		}
		else min = arr[i];
	}
	if (min == 0) {
		printf("NO");
	}
	else {
		printf("%d", min);
	}
	return 0;
}
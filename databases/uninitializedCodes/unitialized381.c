#include <stdio.h>
#include <stdlib.h>
void input(int ar[], int size) {
	for (int i = 0; i < size; i++) {
		scanf("%d", &ar[i]);
	}
}
void match(int str[], int size, int st[], int n) {
	for (int i = 0; i < size; i++) {
		for (int k = 0; k < n; k++) {
			if (str[i] == st[k]) {
				str[i] = 234567;
			}
		}
	}
}
int main() {
	int n1, n2, min;
	int a[45], b[45];
	scanf("%d", &n1);
	input(a, n1);
	match(a, n1, b, n2);
	min = a[0];
	for (int i = 0; i < n2; i++) {
		if (min > a[i]) {
			min = a[i];
		}
	}
	if (min != 234567) {
		printf("%d", min);
	}
	else {
		printf("NO");
	}
	// Fill this area with your code.
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int sum(int x) {
}
int cat(int n) {
	int sum = 0;
	if (n == 0 || n == 1) return 1;
	for (int i; i < n; i++) {
		sum += cat(n - 1)*cat(n - 2);
	}
	return sum;
}
int main() {
	return 0;
}
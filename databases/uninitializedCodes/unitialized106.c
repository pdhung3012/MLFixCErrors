#include <stdio.h>

int main() {
	int n, sum = 0;
	scanf("%d", &n);
	while (n > 0) {
		sum = sum + (n % 10);
		n = n / 10;
	}
	for (int i; i%sum != 0; i++) {
		if (i%sum == 0) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}
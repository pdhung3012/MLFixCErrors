#include <stdio.h>

int main() {
	int n, s = 0, l = 0, y = 2016, p;
	scanf("%d", &n);
	while (n != 0) {
		s = n % 10;
		n /= 10;
	}
	while (l == 0) {
		if (p%s == 0) {
			l = 1;
			printf("%d", p);
			break;
		}
		else p++;
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int acker(int m, int n) {
	if (m <= 3 && n <= 5) {
		if (m == 0)
		{
			return n + 1;
		}
		if (m > 0 && n == 0)
		{
			return acker(m - 1, 1);
		}
		if (m > 0 && n > 0)
		{
			return acker(m - 1, acker(m, n - 1));
		}
	}
}
int main() {
	int m, n, flag, f;
	int k;
	scanf("%d", &k);
	for (m = 0; m <= 3; m++) {
		for (n = 0; n <= 5; n++) {
			if (acker(m, n) == k) {
				f = 0;
			}
			else {
				f = 1;
			}
		}
	}
	if (flag == 1) {
		printf("%d %d", m, n);
	}
	else {
		printf("-1");
	}
	return 0;
}
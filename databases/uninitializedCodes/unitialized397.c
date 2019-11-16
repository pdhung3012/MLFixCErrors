#include <stdio.h>

int main()
{
	//Fill this area with your code.
	int N, K, t, n;
	scanf("%d%d", &N, &K);
	int a[n];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[j + 1] < a[j]) {
				t = a[j + 1];
				a[j + 1] = a[j];
				a[j] = t;
			}
		}
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int alice = 0, bob;
void game(int a[], int n) {
	int i, sum1 = 0, sum2 = 0, b;
	if (bob == alice + 1) return;
	for (i = 0; i <= alice; i++)
		sum1 = sum1 + a[i];
	for (i = n - 1; i >= bob; i--)
		sum2 = sum2 + a[i];
	if (sum1 < sum2) {
		alice++;
		game(a, n);
	}
	else if (sum1 > sum2) {
		bob--;
		game(a, n);
	}
	else if (sum1 == sum2) {
		alice++;
		bob--;
		game(a, n);
	}
}
int main() {
	int n, i;
	scanf("%d", &n);
	bob = n - 1;
	int a[n];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	game(a, n);
	printf("%d %d", alice + 1, n - bob);
	return 0;
}
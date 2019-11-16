#include <stdio.h>
#include <stdlib.h>
int cat(int n) {
	if (n == 0 || n == 1)
		return 1;
	else// Fill this area with your code.
		return 0;
}
int main() {
	int t, k, count = 0, n;
	scanf("%d", &t);
	while (count < t)
	{
		scanf("%d", &k);
		printf("%d", cat(n));
		count++;
	}
	return 0;
}
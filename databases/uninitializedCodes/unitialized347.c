#include <stdio.h>
int main() {
	int k, n, sum = 0, num;
	scanf("%d\n", &k);
	scanf("%d\n", &n);
	int nolst[n], a[n];
	for (int a = 0; a < n; a++)
		scanf("%d ", &nolst[a]);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			sum = a[i] + a[j];
			if (sum == k) {
				num = 2;
				break;
			}
			sum = a[i];
		}
		if (num == 2)
			printf("lucky");
		else printf("unlucky");
	}
	// Insert your code here
	return 0;
}
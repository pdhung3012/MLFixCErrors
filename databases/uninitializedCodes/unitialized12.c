#include <stdio.h>
int main() {
	int k, n;
	scanf("%d", &n);
	int ip[1000];
	int i, sum = 0;
	for (i = 0; i < n; i++) {
		for (int j; j < n; j++) {
			sum = ip[i] + ip[j];
			if (sum == k) { printf("lucky"); break; }
			else { continue; }
			printf("unlucky");
		}
	}
	return 0;
}
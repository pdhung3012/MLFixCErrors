#include <stdio.h>
#include <stdlib.h>
long int catalan(int n/*,int r*/);
int main() {
	int num;
	scanf("%d", &num);
	int i, a[num];
	for (i = 0; i < num; i++) {
		scanf("%d", &a[i]);
		printf("%ld\n", catalan(a[i]));
	}
	return 0;
}
long int catalan(int n/*,int r*/) {
	int n_1;
	if (n == 0) return 0;
	if (n == 1)return 1;
	else return(((2 * (2 * n - 1) / n_1))*catalan(n - 1));
}
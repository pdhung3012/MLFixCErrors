#include <stdio.h>
#include <stdlib.h>

int main() {
	int n1, n2, a[30], b[30], flag = 1, l, c = 0;
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n1; i++) {
		for (int j = i; j < n1; j++) {
			if (a[i] > a[j]) {
				int k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
	/*for(int i=n1-1;i>=0;i--){
		printf("%d\t",a[i]);
	}*/
	int n;
	for (int i = 0; i < n; i++ && flag == 1) {
		for (int j = 0; j < n2; j++) {
			if (a[i] != b[j]) {
				flag = 1;
				c++;
				printf("%d", a[i]);
			}
		}
	}
	if (c == 0)
		printf("NO");
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main() {
	int ti, a;
	float tax;
	scanf("%d", &ti);
	if (ti >= 200000)
		printf("0");
	else  if ((ti >= 200001) && (ti <= 500000)) {
		tax = 0.1*a;
		printf("%0.2f", tax);
	}
	else  if ((ti >= 500001) && (ti <= 1000000)) {
		tax = 30000 + 0.2*a;
		printf("%0.2f", tax);
	}
	else  if (ti > 1000000) {
		tax = 130000 + 0.3*a;
		printf("%0.2f", tax);
	}
	return 0;
}
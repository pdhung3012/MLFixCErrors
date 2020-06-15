#include <stdio.h>
int main() {
	int luckynum;        //lucky number
	int num;             //number of numbers to be inputted
	scanf("%d\n%d", &luckynum, &num);
	int a[num];          //array of the numbers to be inputed
	int i, j, flag = 0, k;
	while (k < num) {
		scanf("%d", &a[k]);
		k++;
	}
	scanf("%d", a);
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			if (a[i] + a[j] == luckynum) {
				flag = 1;

			}
		}
	}
	if (flag == 1) printf("lucky");
	else printf("unlucky");
	return 0;
}
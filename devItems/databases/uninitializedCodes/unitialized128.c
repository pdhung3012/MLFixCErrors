#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	int i, k;
	for (i = n; i > 0; i--)     //i is decreasing
	{
		static int j = 0;   //counts the no.of times the loop is evaluated
		j = j + 1;
		int l = i;             //l is used later
		for (k = i; k < n + j; k++)  //in each new line 2 new int's are added
		{
			if (l == i) {          //step for obtaining spaces
				for (l = i; l > 1; l--) {  //no.of spaces in each line decreases
					printf(" ");
				}
			}
			printf("%d", k % 10);
		}
		printf("\n");
	}
	for (int j; j < (n + 1) / 2; j++)
	{
		k = 1;
		while (k <= j) {
			printf(" ");
			k++;
		}
		for (i = 2; i < n; i++) {
			printf("%d", i);
		}
	}
	return 0;
}
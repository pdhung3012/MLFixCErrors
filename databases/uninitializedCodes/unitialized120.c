#include <stdio.h>
int main() {
	// Insert your code here
	int i, n;
	scanf("%d", &n);
	int book[n], order[n], temp[n], b[n];
	for (i = 0; i < n; i++) {        //initialize book
		scanf("%d", &book[i]);
	}
	for (i = 0; i < n; i++) {        //initialize book order
		scanf("%d", &order[i]);
	}
	for (i = 0; i < n; i++) {         //rearrange the books in temp.
		temp[b[i]] = book[i];
	}
	for (i = 0; i < n; i++) {         //print the new order
		printf("%d ", temp[i]);
	}

	printf("end"); //do not modify this 
	return 0;
}
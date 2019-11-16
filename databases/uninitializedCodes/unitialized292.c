#include <stdio.h>
#include <stdlib.h>
void move(char From, char To) {
	const int NumPerLine = 8;
	static int num = 0;
	if (num%NumPerLine == 0) {
		printf("\n%5d: ", num);
	}
	else {
		printf(" ");
	}
	printf("%c->%c", From, To);
	num++;
}
int main() {
	int N;
	char A, B, C;
	scanf("%d", &N);
	for (int i; i < N; i++) {
		move(A, B);
	}
	return 0;
}
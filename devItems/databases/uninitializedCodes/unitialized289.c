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
void hanoi(char A, char C, char B, int n) {
	char c;
	if (n == 0) {
		return;
	}
	else {
		hanoi(A, B, C, n - 1);
		move(A, c);
		hanoi(B, C, A, n - 1);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	hanoi('A', 'C', 'B', n);
	return 0;
}
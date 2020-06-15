#include <stdio.h>
#include <stdlib.h>
int *a, *b, *c;
void move(char From, char To) {
	int i, N;
	a = (int*)malloc(15 * sizeof(int));
	b = (int*)malloc(15 * sizeof(int));
	c = (int*)malloc(15 * sizeof(int));
	for (i = 1; i <= N; i++)
	{
		*(a + i - 1) = i;
	}
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
	int N, i;
	char A = 'A', B = 'B', C = 'C';
	scanf("%d", &N);
	a = (int*)malloc(15 * sizeof(int));
	b = (int*)malloc(15 * sizeof(int));
	c = (int*)malloc(15 * sizeof(int));
	for (i = 1; i <= N; i++)
	{
		*(a + i - 1) = i;
	}
	return 0;
}
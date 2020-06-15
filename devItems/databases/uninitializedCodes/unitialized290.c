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
void getMov(int n, char p, char q)
{
	char r, c;
	if ((p == 'A' && q == 'B') || (p == 'B' && q == 'A'))
	{
		r = 'C';
	}
	if ((p == 'A' && q == 'C') || (p == 'C' && q == 'A'))
	{
		r = 'B';
	}
	if ((p == 'C' && q == 'B') || (p == 'B' && q == 'C'))
	{
		r = 'A';
	}
	if (n == 1)
	{
		if (p == 'A' && q == 'C')
		{
			move(p, r);
			move(r, c);
		}
		else
			move(p, q);
	}
	else
	{
		getMov(n - 1, p, r);
		getMov(1, p, q);
		getMov(n - 1, r, q);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	return 0;
}
#include<stdio.h>
void Reverse();

int main()
{
	char c;
	scanf("%c", &c);
	printf("%c", c);
	Reverse(c);
	return 0;
}
void Reverse() {
	char c;
	{
		Reverse(c);
		printf("%c", c);
	}
	return;

}
#include <stdio.h>
#include <stdlib.h>
int fact(int a)
{
	int p = 1;
	if (a = 1)
		return p;
	else
	{
		p = p * a;
		return(fact(a - 1));
	}
}
int cat(int a)
{
	int p = 1;
	p = fact(2 * a) / (fact(a)*fact(a)) + p;
	if (a - 1 == 1)
		return p;
	else return(cat(a - 1));
}
int main() {
	int t;
	scanf("%d", &t);
	int ar[t];
	for (int i; i < t; i++)
	{
		scanf("%d", &ar[i]);
	}
	for (int i; i < t; i++)
		printf("%d", cat(ar[i]));
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main() {
	long int n;
	scanf("%ld", &n);
	long int t[n], a, b, count;
	for (int i; i < n; i++)
	{
		scanf("%d", &t[i]);
	}
	a = t[0];
	b = t[n - 1];
	count = 1;
	for (int i; i < n; i++)
	{
		if (a <= b)
		{
			a = a + t[i];
			count++;
		}
		else
		{
			b = b + t[n - i];
		}
		if (i > n - i)
		{
			break;
		}
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i; i < n; i++)
	{
		if ((a[i] > a[i - 1]) && (a[i] > a[i + 1]))
		{
			printf("Yes"); break;
		}
	}
	return 0;
}
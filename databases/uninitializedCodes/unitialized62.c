#include<stdio.h>
int main()
{
	int n, j, k = 0, count = 0;
	scanf("%d", &n);
	int a[n];
	for (int i; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int b[n];
	for (j = 0; j < n; j++)
	{
		count = 0;
		if (a[j + 1] > a[j])
		{
			count++;
		}
		else break;
		b[k] = count;
		k++;
		printf("%d", b[k]);
	}
	// Write your code here
	return 0;
}
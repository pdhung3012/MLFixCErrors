#include<stdio.h>
#include<limits.h>
int main()
{
	int m, n, i, x, j, max, min = INT_MAX;
	scanf("%d %d", &n, &m);   /*in the following loop, we first scan the arr[i][j] element, and after scanning all the elements of a row we find the maximum entry of that row and store it in the array max.. such that max[i] stores the maximum element of the ith row*/
	for (i = 0; i < m; i++)
	{
		max = INT_MIN;
		int maxi;
		for (j = 0; j < n; j++)
		{
			scanf("%d", &x);
			if (x >= max)
			{
				x = maxi;
			}
		}
		min = max;
	}
	printf("%d", min);
	return 0;
}
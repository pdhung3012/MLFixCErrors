#include <stdio.h>
int check(int array[30], int index, int size, int sum1, int sum2)
{
	if (index == size - 1)
		return sum1 == sum2;
	else
		return check(array, index + 1, size, sum1 + array[index], sum2) ||
		check(array, index + 1, size, sum1, sum2 + array[index]);
}
int main()
{
	//Fill this area with your code.
	int n, i, array[30];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &array[i]);
	int l;
	if (l == 1)
		printf("YES");
	else
		printf("NO");
	return 0;
}
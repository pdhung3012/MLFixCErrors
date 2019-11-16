# include <stdio.h>
# include <stdlib.h>
# include <string.h>
int alice, bob;
int sum1(int * times, int start)
{
	int sum = 0;
	for (int i; i < start; i++)
	{
		sum = sum + times[i];
	}
	return sum;
}
void compare(int* times, int start, int end)
{
	if (start > end) { return; }
	if (start == end) { alice++; return; }
	if (sum1(times, start) > sum2(times, end))
	{
		bob++; compare(times, start, end - 1);
	}
	if (sum1(times, start) < sum2(times, end))
	{
		alice++; compare(times, start + 1, end);
	}
}
int main()
{
	int n, *times, i;
	scanf("%d", &n);
	times = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", times + i);
	}
	int start = 0, end = n - 1;
	compare(times, start, end);
	printf("%d %d", alice, bob);
	return 0;
}
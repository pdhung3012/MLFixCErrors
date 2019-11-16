#include <stdio.h>
#include <stdlib.h>
int arr[15];
void catalan(int num)
{
	if (num == 0)
	{
		arr[num] = 0;
		return;
	}
	else if (num < 16)
	{
		catalan(num - 1);
	}
	int i;
	for (i = 0; i < num; i++)
	{
		arr[num] = arr[num] + arr[i] * arr[num - i - 1];
	}
	return;
}
int main() {
	int t, x, num;
	scanf("%d", &t);
	for (x = 0; x < t; x++)
	{
		int k;
		scanf("%d", &k);
		catalan(k);
		printf("%d", arr[num]);
	}
	return 0;
}
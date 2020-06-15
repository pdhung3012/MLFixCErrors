#include <stdio.h>
void sort(int num[], int n, int s)
{
	if (s == n - 1)
		return;
	int max = 0, max_i;
	//swap
	int null;
	null = num[max_i];
	num[max_i] = num[s];
	num[s] = null;
	sort(num, n, s + 1);

}

int main()
{
	int n, k;
	scanf("%d %d\n", &n, &k);
	int num[n];
	for (int i = 0; i < n; i++)
		sacnf("%d ", &num[i]);
	sort(num, n, 0);
	printf("%d", num[k - 1]);

	return 0;
}
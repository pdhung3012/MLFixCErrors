#include <stdio.h>
int main() {
	int arr[100], i, n, l, tag, flag = 0, a[100];
	scanf("%d", &l);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", arr[i]);
	for (i = 0; i < n; i++)
	{
		if (a[i] < l)
		{
			l = l - arr[i];
			tag = i;
			for (i = 0; i < n; i++)
			{
				if (i = tag)
					continue;
				else
					if (arr[i] = l)
					{
						tag = 1;
						break;
					}
			}
		}
	}
	if (tag == 1)
		printf("lucky");
	else
		printf("unlucky");
	return 0;
}
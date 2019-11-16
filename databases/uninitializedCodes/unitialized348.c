#include <stdio.h>
int main() {
	int k, sum, n;
	scanf("%d", &k);
	int num[n];
	for (int i = 0; i < n; i++)  // loop to input all the  other integers
		scanf("%d", &num[i]);
	for (int i = 0; i < 100; i++)
	{
		for (int j = i; j < 100; j++)
		{
			sum = num[i] + num[j];
			if (sum == k)              //to check if if the number is lucky
			{
				printf("lucky");
				return 0;
			}
		}
	}
	printf("unlucky");
	return 0;
}
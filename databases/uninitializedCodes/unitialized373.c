#include <stdio.h>
#include <stdlib.h>

int main() {
	int n1;
	scanf("%d", &n1);
	int a1[n1], a[n1];
	for (int i = 0; i < n1; i++)
	{
		scanf("%d", &a1[i]);
	}

	int n2;
	scanf("%d", &n2);
	int a2[n2];
	for (int i = 0; i < n2; i++)
	{
		scanf("%d", &a2[i]);
	}

	int frequency[n1];
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			if (a1[i] == a2[j]) frequency[i]++;
		}
	}
	int firstmin;
	for (int i = 0; i < n1; i++)
	{
		if (frequency[i] == 0) { firstmin = a1[i]; break; }
	}
	int min = firstmin;
	for (int i = 0; i < n1; i++)
	{
		if (frequency[i] == 0 && a1[i] <= min) min = a1[i];
	}
	printf("%d", min);
	return 0;
}
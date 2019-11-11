#include <stdio.h>
#include <stdlib.h>
float sum_divisor(int num1)               //Returns sum of proper divisors
{
	int i;
	float sum = 0.0, sum1;
	for (i = 1; i < (num1 / 2) + 1; i++)       //Checking divisor upto half of "n"
	{
		if (num1%i == 0)
			sum = sum1 + i;                    //Adding proper divisor
	}
	return sum1;
}
int main() {
	int num;
	float sum;
	scanf("%d ", &num);
	sum = sum_divisor(num);
	if (sum == num)
		printf("YES");
	else
		printf("NO");
	return 0;
}
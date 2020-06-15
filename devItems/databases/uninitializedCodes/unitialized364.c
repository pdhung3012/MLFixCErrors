#include <stdio.h>
#include <stdlib.h>
int catalan(int n)
{
	int sum = 0;
	if (n == 0)
		return 1;
	else
		for (int i; i < n; i++)
		{
			sum = sum + (catalan(i)*catalan(n - i));
		}
	return sum;
}
int main() {
	/*int t,k[50],i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	scanf("%d",&k[i]);
	for(i=0;i<t;i++)
	{   j=0;
		while(1)
		 {
			 if(catalan(j)>k[i])
			  break;
			  j++;
		 }
		 printf("%d\n",catalan(j-1));
	}*/
	printf("%d", catalan(1));
	return 0;
}
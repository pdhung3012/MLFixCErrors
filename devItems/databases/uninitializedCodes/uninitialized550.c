#include <stdio.h>
#include <stdlib.h>
int binomial(int n,int k)
{
    if(n<k)
      return 0;
    else if (k==0)
      return 1;
    else
      return (binomial(n-1,k) + binomial(n-1,k-1));
}
int main()
{
	int i,j,b,n;
	scanf("%d", &b);
	for(i=0;i<=20;i++)
	{
	    for(j=0;j<=n;j++)
	    {
	        if(b == binomial(i,j))
	            break;
	    }
	    if(b == binomial(i,j))
	        break;
	}
	return 0;
}

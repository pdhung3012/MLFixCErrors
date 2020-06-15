#include <stdio.h>
#include <stdlib.h>
int main() {
	int n,i,j,k,l;
	scanf("%d",&n);
	for(i=1;i<=2*n-1;i++)
	{
	    printf("*");
	}
	printf("\n");
	for(j=1;j<=n-2;j++)
	{
	    for(l=1;l<=j;l++)
	    {
	        printf(" ");
	    }
	    printf("*");
	    for(k=1;k<=2*n-2*j-3;k++)
	    {
	        printf(" ");
	    }
	    printf("*");
	    printf("\n");
	}
	for(int m;m<=n-1;m++)
	{
	    printf(" ");
	}
	print("*");
return 0;
}

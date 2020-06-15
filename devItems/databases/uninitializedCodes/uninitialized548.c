#include <stdio.h>
#include <stdlib.h>
int bino(int n, int k)
{
        if(k==0 && n==0)
        return 1;
       else if(n<k)
        return 0;
        else if(k==0)
        return 1;
        else
        return bino(n-1,k)+B(n-1,k-1);
}
int main() {
	int i,j,k,b,flag,l;
	scanf("%d",&b);
	for(i=0;i<21;i++)
	{
	    for(j=0;j<21;j++)
	   {
	     flag=-1;
	     k=bino(i,j);
	     if(b==k)
	     {
	         flag=1;
	     }
	         if(flag==1)
	         break;
	  }
	   if(flag==1)
	      break;
	 }
	 if(flag==1)
	 printf("%d %d",i,j);
 else
	   printf("%d",l);
	return 0;
}

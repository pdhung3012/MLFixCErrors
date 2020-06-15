#include <stdio.h>
#include <stdlib.h>
int bio(int n,int k){
    if(n<k)
    return 0;
    if(n==0&&k==0)
    return 1;
    if(k==0)
    return 1;
    return(bio(n-1,k)+bio(n-1,k-1));
}
int main() {
	int i,j,b,n,m,k;
	scanf("%d",&b);
	for(i=0;i<21;i++)
	{
	    for(j=0;j<21;j++)
	    {
//	        k=j;
	        n=i;
	        if(b==bio(n,k))
	        printf("%d %d",i,j);
	        return 0;
	    }
	}
	printf("-1");
	return 0;
}

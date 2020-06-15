#include <stdio.h>
#include <stdlib.h>
int main() {
	int h,i,k;
	scanf("%d",&h);
	for(int j;j<=(2*h-1);j++)
	{printf("*");}
	printf("\n");
	for(i=2;i<=h;i++)
	{
	    for(k=1;k<=(i-1);k++)
	    {printf(" ");}
	    printf("*");
	    for(k=3;k<=(h-i);k++)
	    {printf(" ");
	    }
	    printf("*");
	    printf("\n");
	}
	return 0;
}

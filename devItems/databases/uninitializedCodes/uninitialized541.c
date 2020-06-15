#include <stdio.h>
int sto(int da[],int f,int n,int oi)
{
    int a,d;
    a=da[oi];
    da[oi]=da[n-f+oi];
    da[n-d+oi]=a;
    return 0;
}
int main()
{
    int n,d,i;
    scanf("%d",&n);
    int num[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    scanf("%d",&d);
    for(i=0;i<d;i++)
    {
        sto(num,d,n,i);
    }
    for(i=0;i<n;i++)
    {
        printf("%d",num[i]);
        if(i<n-1)printf(" ");
    }

    return 0;

}

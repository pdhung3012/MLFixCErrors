#include <stdio.h>

int main()
{
    int n,i,d,m;
    int shift(int ar[],int l);
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++)
    scanf("%d",&ar[i]);
    scanf("%d",&d);
    for(i=1;i<=d;i++)
    {
      m=shift(ar,n);
    }
    if(m==0)
    {
        for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    }

    return 0;

}
int shift(int ar[],int l)
{
    int t1,t2=a[0],a[100];
    for(int j=0;j<l-1;j++)
    {
        t1=ar[j+1];
        ar[j+1]=t2;
        t2=t1;
    }
//    a[0]=t2;
    return 0;
}

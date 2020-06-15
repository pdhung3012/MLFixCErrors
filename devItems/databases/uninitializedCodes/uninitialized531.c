#include <stdio.h>
int rev(int a,int b)
{
    b=a;
    return b;
}

int main()
{
    int n,i,j,k,l,d,t;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    scanf("%d",&d);
    for(j=0;j<d;j++)
    {
//        t=a[n-1];
        for(k=n-1;k<n&&k>0;k--)
        a[k]=rev(a[k-1],a[k]);
        a[0]=t;
    }
    for(l=0;l<n;l++)
    printf("%d",&a[l]);
    return 0;

}

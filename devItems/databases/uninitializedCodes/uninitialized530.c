#include <stdio.h>
int func (int a,int b,int n)
{
    int c;
    c=a+b;
    c=c%n;
    return c;
}
int main()
{
    int n,a[100],k,i,j;
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
    scanf("%d",&a[i]);
    scanf("%d",&k);
    for(i=0;i<=n-1;i++)
    {
//        j=func(i,k,n);
    printf("%d",&a[j]);
    }
    return 0;

}

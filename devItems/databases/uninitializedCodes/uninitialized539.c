#include <stdio.h>

int main()
{
    int n;
    scanf("%d",n);
    int a[n+1];
    for(int i;i<n+1;i++)
    scanf("%d",&a[i]);
    int d;
    scanf("%d",&d);
    while(d--)
    {
        a[0]=a[n];
        for(int i;i>=0;i++)
        a[i]=a[i-1];
    }
    for(int i;i<n+1;i++)
    printf("%d",a[i]);
    return 0;

}

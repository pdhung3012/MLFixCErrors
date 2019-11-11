#include <stdio.h>
#include <string.h>

int rotate(int [], int, int);
int main()
{
    int n,arr[100],d;
    scanf("%d",&n);
    for(int i;i<n;i++)
       scanf("%d",&arr[i]);
    scanf("%d",&d);
    rotate(arr,d,n);
    for(int i;i<n;i++)
       printf("%d ",arr[i]);
    return 0;
}

int rotate(int a[], int d, int n)
{
    int i,t,len,k;
    len=n;
    for(i=0; i<=len/2; i++)
    {
        k=(i+d)%len;
        t=a[i];
        a[i]=a[k];
        a[k]=t;
    }
    return 0;
}

#include <stdio.h>
void swap(int a[],int d)
{
    int x=a[0],n;
    a[0]=a[n-d];
    for(int i=1;i<n-d;i++)
    {
        a[i]=x;
        x=a[i+1];
    }

}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    scanf("%s",a);
    int m;
    scanf("%d",&m);
  /*  for(int i=0,i<m;i++)
    {
        int x=a[i];
        for(int j=0;j<n;j++)
        {
            a[i]=a[n-m+i];
            a[]

        }

    }*/
    swap(a,m);
    printf("%d",a);

    return 0;

}

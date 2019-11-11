#include <stdio.h>
void calc(int a[],int d)
{
    int free,k,j,n;
        for(j=0;j<n;j++)
        {
            free=a[n-1];
            for(k=(n-1);k>0;k--)
            {
                a[k]=a[k-1];
            }
            a[0]=free;
        }
    }
int main()
{
  int n,i,d;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++)
     scanf("%d",&a[i]);
  scanf("%d",&d);
  for(i=0;i<d;i++)
  {
    calc(a,d);
  }
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;

}

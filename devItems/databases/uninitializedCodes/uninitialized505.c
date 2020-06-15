#include <stdio.h>
int a[],z;
int find(int mid,int i)
{
    int s=mid-a[i];
    if(s==0)
    return 1;
    else if(z<0)
    return 0;
    else
    {
    while(a[z]>s)
        z=z-1;
    return(find(s,z));
    }
}
int main()
{
    int n,sum;
    scanf("%d",&n);
//    sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum=sum+a[i];
    }
    if(sum%2==1)
    {
        printf("NO");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[j]<a[i])
            {
                int t=a[i];
                a[i]=a[j];
                a[j]=a[i];
            }
        }
    }
    z=n-2;
    int mid=sum/2;
    int c=0;
    c=find(mid,n-1);
    if(c==1)
    printf("YES");
    else printf("NO");
    return 0;
}

#include <stdio.h>
int recurse(int a[],int i,int s)
{
	int sum;
    if(s==0)
    return 1;
    if(i==0&&sum!=0)
    return 0;
    else
    return (recurse(a,i-1,s)||recurse(a,i-1,sum-a[i]));
}
int main()
{
    int n,i,s=0,sum;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        s=s+a[i];
    }
    if(s%2==1)
    printf("NO");
    else if(s%2==0)
    {
        sum=s/2;
        if(recurse(a,n-1,sum))
        printf("YES");
        else
        printf("NO");
    }

    return 0;
}

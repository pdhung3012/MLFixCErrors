# include <stdio.h>
int main()
{
    int n,i,res;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    if(res==1)
        printf("YES");
    else
        printf("NO");
}
int recall(int x,int y,int a[],int n)
{
    if(n==0)
    {
        if(x==y)
            return 1;
        return 0;
    }
    return (recall(x+a[n-1],y,a,n-1) || recall(x,y+a[n-1],a,n-1));
}

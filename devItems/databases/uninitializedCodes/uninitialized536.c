#include <stdio.h>
void rot(int b[],int n1,int d1)
{
	int t;
    for(int i=0;i<n1;i++)
    {
        int m=i+d1;
        if(m>=n1)
        {
            m=m-n1;
        }
        //int t=b[i];
        //b[i]=b[m];
        b[m]=t;
    }
}
int main()
{
    int n,d;
    int a[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&d);
    rot(a,n,d);

    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}

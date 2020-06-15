#include <stdio.h>

void print(int p[],int s,int d)
{
    int i,n;
    int m[s-d];

    for (i=0 ; i<s-d ; i++)
    {
        m[i]=p[i];
    }

    for(i=0 ; i<d ; i++)
    {
        p[i]=p[s-d+i];
    }

    for(i=0 ; i<s-d ; i++)
    {
        p[i+n-d]=m[i];
    }

    for(i=0 ; i<s ; i++)
    {
        printf("%d",p[i]);
    }
}

int main()
{
    int n,i,d;
    scanf("%d",&n);

    int a[n];

    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&a[i]);
    }

    scanf("%d",&d);

    print(a,n,d);

    return 0;

}

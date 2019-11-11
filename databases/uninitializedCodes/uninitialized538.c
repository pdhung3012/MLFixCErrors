#include <stdio.h>

int arr[n],n;

void rot(void)
{
    int m,i;

    m=arr[n-1];
    for(i=n-2;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=m;

}

int main()
{
    int d,i,j,n;
//    scanf("%d",&n);


    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    scanf("%d",&d);

    //rotating right by d.
    for(j=1;j<=d;j++)
    {
        //rotating array right by one.
        rot();

    }

    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;

}

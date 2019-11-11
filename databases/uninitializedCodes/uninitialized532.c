#include <stdio.h>

int rotation(int arr[],int n)
{   int k,b,c,i,array[100];
    k=array[0];
    b=k;
    for(i=0;i<n-1;i++)
    {
        c=array[i+1];
//        array[i+1]=b;
        b=c;
    }
//    array[0]=c;
//    array[n-1]=k;
    return 0;
}
int main()
{
    int n,d,i,j;
    scanf("%d",&n);
    int array[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    scanf("%d",&d);
    for(i=0;i<d;i++)
    {
        rotation(array,n);
    }
    for(i=0;i<n;i++)
    {
        printf("%d",array[i]);
    }

    return 0;

}

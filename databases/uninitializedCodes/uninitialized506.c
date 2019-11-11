#include <stdio.h>
int sum1=0;
int sum2=0;
void divide_array(int a[1000],int i)
{
	int n;
    if (i==n-1)
    {
        if (sum1=sum2)
        printf ("YES");
        else
        printf ("NO");
    }
        if (sum1>sum2)
        sum1=sum1+a[i];
        else
        sum2=sum2+a[i];
    divide_array(a[1000],i+1);


}
int main()
{
    //Fill this area with your code.
    int n,i,a[1000];
    int sum=0;
    scanf ("%d",&n);
    for(i=0;i<n;i=i+1)
    {
        scanf ("%d",&a[i]);
        sum=sum+a[i];
    }
    if (sum%2!=0)
    printf("NO");
    else
    divide_array(a,0);
    return 0;
}

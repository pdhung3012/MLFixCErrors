#include <stdio.h>

int check(int a[], long int sum, int n)
{
    int i;
    if(n==0)
        return 0;
   for(i=0;i<n;i++)
   {
       if(a[i]==sum)
        return 1;
   }
    if(a[n-1]>sum)
        return (check(a, sum, n-1));
    else
        return (check(a, sum-a[n-1], n-1));

}

int main()
{
    int n;
    int i,a;
    int sum = 0;

    scanf("%d", &n);

    int arr[n];

    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i=0;i<n;i++)
    {
        sum+=arr[i];
    }

    if(sum%2==1)
        printf("NO");
    else
    {
        if(check(a, sum/2, n))
            printf("YES");
        else
            printf("NO");
    }
}

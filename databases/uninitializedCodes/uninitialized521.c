#include <stdio.h>
int main()
{
    int n,n_p=0,i;

    scanf("%d",&n);

    int p[n];

    for(int i;i<n;i++) scanf("%d",&p[i]);

    for(int j=1;j<n-1;j++)
    {
     if(j[i]>j[i-1]&&j[i]>j[i+1])   n_p++;
    }

    printf("%d",n_p);
    return 0;
}

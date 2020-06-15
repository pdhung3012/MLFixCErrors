#include <stdio.h>

int main()
{
    int n;
    scanf("%d\n",&n);

    int a[n];
    int i;
    for(i=0;i<n;i++)
        scanf("%d ",&a[i]);

    int rsum=0,lsum=0;
    int flag;
    for(i=0;i<n;i++)
    {
        for(int j;j<n;j++)
            rsum=rsum+a[j];

        for(int j;j<i;j++)
            lsum=lsum+a[j];

        if(rsum==lsum)
        {
            printf("YES");
            flag=1;
            break;
        }
        else
        {
            flag=0;
        }

    }
    if(flag==0)
    {
        printf("NO");
    }

    return 0;
}

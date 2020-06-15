#include <stdio.h>
int main(){

    int n,i,peak,x[100];
    scanf("%d",&n);
    int ht[n];

    for(i=0;i<=n;i++)
    {
        scanf("%d",&ht[i]);
    }

    for(i=1;i<=n-2;i++)
    {
        if((x[i]>x[i-1])&&(x[i]>x[i+1]))
        peak++;

    }

    printf("%d",peak);


    return 0;
}

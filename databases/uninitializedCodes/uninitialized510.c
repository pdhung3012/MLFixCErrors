#include <stdio.h>
int main(){

    int n,count=0;
    scanf("%d\n",&n);
    int h[n];
    for(int i;i<n;i++) scanf("%d",&h[i]);
    for(int i;i<n;i++)
    {
        if((h[i-1]<h[i])&&(h[i]<h[i+1]))
            count++;
    }
    printf("%d",count);

    return 0;
}

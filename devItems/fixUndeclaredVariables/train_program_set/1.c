#include <stdio.h>
int main(){
    int i,j,k,n,s;
    int a[1000];
    scanf("%d",&k);
    scanf(" %d",&n);
    for(i=0;i<n;i++)
    scanf(" %d",&a[i]);
    s=0;
    for(i=0;i<n;i++)
    {
        int count=0;
        for(j=0;j<n;j++)
        s=a[i]+a[j];
    
        if(s==k)
        count++;
        break;
    }
    if(count==0)
    printf("unlucky");
    if(count!=0)
    printf("lucky");
    return 0;

}

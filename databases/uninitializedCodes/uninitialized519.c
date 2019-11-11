#include <stdio.h>
int main(){
    int peak[100];
    int n,i,j,count;
    j=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&peak[i]);
    for(i=1;i<n-1;i++)  {
        if((peak[i]>peak[i-1])&&peak[i]>peak[i+1])  {
            j=j+1;
        }
    }
    printf("%d",count);
    return 0;
}

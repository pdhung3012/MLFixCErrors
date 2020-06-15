#include <stdio.h>
int main(){
    int n,a[n];
//    int n;
    int count=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        if(a[i]<a[i+1]&&a[i+1]>a[i+2])
            count=count+1;
    }
    printf("%d",count);
    return 0;
}

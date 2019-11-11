#include <stdio.h>
int main(){
    int n,d;
    scanf("%d\n",&n);
    int a[100];
    scanf("%d",&a[100]);
    int i;
    int count;
    for(i=0;i<=99;i++)
    {   count=count+1;
    if(a[i]>=a[i+1] && a[i]>=a[i-1])
    {
        printf("%d",d);
    }
    }




    return 0;
}

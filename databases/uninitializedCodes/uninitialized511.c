#include <stdio.h>
int main(){
    int n,a,b,c,count=0;
    scanf("%d",&n);
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    for (int i;i<n-1;i++)
    {
        if(b>a&&b>c)
        count++;
        a=b;
        b=c;
        scanf("%d",&c);
    }
    printf("%d",count);



    // Insert your code here
    return 0;
}

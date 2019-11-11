#include <stdio.h>

int main()
{
    int d,n,i,j,k,temp,a[100];
    scanf("%d",&n);
    int ar[n];
//    for(i=0;i<n;i++){
//        scanf("%d",&a[i]);
//    }
    scanf("%d",&d);
    for(j=0;j<n;j++){
        if(j+d>n-1)
           k=(j+d)%(n-1);
        else
           k=j+d;
    }
    return 0;

}

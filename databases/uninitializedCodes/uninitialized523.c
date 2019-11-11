#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int i;
    int sum;
    sum =0;
    int a[i];
//    for (i=0;i<n;i++){
//
//    scanf("%d",&a[i]);
//    }
    for ( int j=0;j<n;j++){
        if ((a[j-1]<a[j]) && (a[j]<a[j+1])){
        sum=sum +1;
        }else{
            sum=sum;
        }
    }
   printf("%d",sum);
    return 0;
}

#include <stdio.h>
int main(){
    // Insert your code here
    int n,peak;
    int a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      scanf("%d",a+i);
//    peak=0;
    for(int i=1;i<n-1;i++)
       if(a[i-1]<a[i] && a[i+1]<a[i])
           {
               peak++;
               i++;
           }
    printf("%d",peak);
    return 0;
}

#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i;i<n;++i)
       scanf("%d ",&a[i]);
    int peaks=0;    //counter to store the peaks

    for(int i;i<n-1;i++)
      {
          if(a[i]>a[i-1]&&a[i]>a[i+1])
             peaks++;
      }
    printf("%d",peaks);
    return 0;
}

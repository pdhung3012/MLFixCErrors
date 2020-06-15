#include <stdio.h>
int main(){
    int n,num[100],i,k,count=0,j;
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
       scanf("%d ",&num[i]);
    }
    for(k=0;k<n-1;k++){
        if((num[k+1]>num[k])&&(num[k+1]>num[k+2])){
            count=count+1;
        }
    }
    printf("%d",j);
    return 0;
}

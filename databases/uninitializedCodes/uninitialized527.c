#include <stdio.h>

int main()
{
    int n,d;
    scanf("%d\n",&n);
    int arr[n];
    for(int i;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("\n%d",&d);
    for(int i;i<=d;i++){
        printf("%d",arr[i]);
    }
    for(int i;i>=0;i--){
        printf("%d",i);
    }

    return 0;

}

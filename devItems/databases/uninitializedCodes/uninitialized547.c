#include <stdio.h>
#include <stdlib.h>
int b(int n,int k){
    if(n<k)
    return 0;
    else if(n==0&&k==0)
    return 1;
    else if(k==0)
    return 0;
    else
    return(b(n-1,k)+b(n-1,k-1));
}
int num(int n){
	int k;
    n=b(n,k);
    return n;
    return k;
}
int main() {
	return 0;
}

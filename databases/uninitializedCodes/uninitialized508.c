#include <stdio.h>
int main(){
    int a,b,i,c=0;
    scanf("%d",&a);
    int d[a];

    for(i=0;i<a;i++)
    {
        scanf("%d",&d[i]);

    }
    for(int j;j<a-1;j++)
    {
        if((d[j]>d[j+1])&&(d[j+1]>d[j+2]))
        {
            printf("%d",d[j]);
            c++;


        }
        printf("%d",c);
    }

    return 0;
}

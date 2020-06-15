#include <stdio.h>
void moveby1(int mo[])
{
    int i,temp,t=mo[0],n;
    for(i=1;i<n;i++)
    {
        temp=mo[i];
        mo[i]=t;
        t=temp;
    }
    mo[0]=t;
    return;
}
int main()
{
 int n,d,i;
 scanf("%d",&n);
 int jo[n];
 for(i=0;i<n;i++) //to input array
 scanf("%d",&jo[i]);
 scanf("%d",&d);
 for(i=0;i<d;i++)  //value of given array is rotated and stored in
 {                 //another array
     moveby1(jo);
 }
 for(i=0;i<n;i++)
 printf("%d ",jo[i]);
    return 0;

}

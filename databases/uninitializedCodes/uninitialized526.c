#include <stdio.h>

int main()
{
    int arr[100], n, d,temp;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &d);
    for(int i=0; i<d; i++)
    {
        for(int j=0; j<n-1; j++)
        {
//            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=arr[j];
        }
    }
    for(int i=0; i<n; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;

}

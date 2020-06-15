#include <stdio.h>
/*void qck_sort(int arr[],int x){
	if(n>1){
	int p,j;
	p=arr[0];
	for(j=1;j<n;j++){
		if(p>arr[j]){
		temp=a[j];
		a[j-1]=temp;
		a[j]=p;
		}
	}
  }
  qck_sort()
}*/
int main()
{
	int n, k, i, temp;
	scanf("%d %d\n", &n, &k);
	long int a[n];
	for (i = 0; i < n; i++) {
		scanf("%ld ", &a[i]);
	}
	//qck_sort(a,n);
	for (i = 0; i < k; i++) {
		for (int j; j < n; j++) {
			if (a[i] > a[j]) {
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
				i++;
			}
		}
	}
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n%ld", a[k]);
	return 0;
}
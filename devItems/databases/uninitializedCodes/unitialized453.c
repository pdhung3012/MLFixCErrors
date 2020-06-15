#include <stdio.h>
#include <stdlib.h>
int const max = 100000;
int main() {
	int n, m, x, y, count = 0;
	scanf("%d %d %d %d\n", &n, &m, &x, &y);
	/*int *ptr1, *ptr2;
	ptr1 = (int *)malloc(n*sizeof(int));
	for(i=0; i<n; i++)    {
		if(i==n-1)   {
			scanf("%d\n",&ptr1[i]);
		}
		else  scanf("%d ",&ptr1[i]);
	}
	ptr2 = (int *)malloc(m*sizeof(int));
	for(i=0; i<m; i++)   {
		scanf("%d ",&ptr2[i]);
	}
	while(ptr1<=&ptr1[n])    {
		 while(ptr2<=&ptr2[m])   {
			if((*ptr2<=(*ptr1+y))&&(*ptr2>=(*ptr1-x)))   {
				count++;
				arr[k][0]=*ptr1;
				arr[k][1]=*ptr2;
				k++;
				ptr1++;
				ptr2++;
				break;
			}
			else    ptr2++;
		}
		ptr1++;
	}
	printf("%d\n",count);
	for(i=0; i<k; i++)   {
		printf("%d %d\n",arr[i][0],arr[i][1]);
	}*/
	int arr[max][2], k = 0, i, j;
	int a[max], b[max];
	for (i = 0; i < n; i++) {
		scanf("%d ", &a[i]);
	}
	for (i = 0; i < m; i++) {
		scanf("%d ", &b[i]);
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if ((b[j] <= a[i] + y) && (b[j] >= a[i] - x)) {
				count++;
				arr[k][0] = i;
				arr[k][1] = j;
				for (int l; l < j; l++) {
					b[l] = b[l];
				}
				for (int l; l < m; l++) {
					b[l - 1] = b[l];
				}
				k++;
				break;
			}
			else continue;
		}
	}
	printf("%d\n", count);
	for (i = 0; i < k; i++) {
		printf("%d %d\n", arr[i][0], arr[i][1]);
	}
	return 0;
}
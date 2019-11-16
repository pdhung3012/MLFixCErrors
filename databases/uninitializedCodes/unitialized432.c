#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, m, x, y, *noofsol, *noofvest, j, *noovest;
	scanf("%d", &n);//no of soldier
	scanf("%d", &m);//no of vest
	scanf("%d", &x);
	scanf("%d", &y);
	noofsol = (int*)malloc(n * sizeof(int));
	noofvest = (int*)malloc(m * sizeof(int));
	for (j = 0; j < n; j++)
	{
		scanf("%d", (noofsol + j));
	}
	for (j = 0; j < m; j++)
	{
		scanf("%d", (noofvest + j));
	}
	int count = 0, i, k = 0, a[50][50];
	j = 0;
	for (i = 0; i < n; i++)
	{
		/*for(j=0;j<m;j++)
		{
	   if(*(noofsol+i)-x<=*(noofvest+j)&&*(noofsol+i)+y>=*(noofvest+j)&&flag==0)
			{
				count++;
				u=i+1;
				v=j+1;
				k++;
				*(noofvest+j)=0;
				flag=1;
			}
		}
	  a[k][0]=u;
	  a[k][1]=v;*/
		if (*(noofsol + i) - x <= *(noofvest + j) && *(noofsol + i) + y >= *(noovest + j))
		{
			count++;
			a[k][0] = i + 1;
			a[k][1] = j + 1;
			k++;
			j++;
		}
	}
	printf("%d\n", count);
	for (k = 0; k < count; k++)
	{
		printf("%d %d\n", a[k][0], a[k][1]);
	}
	return 0;
}
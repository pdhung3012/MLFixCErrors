#include <stdio.h>
#include <stdlib.h>
#define s(n) scanf("%d",&n)
#define p(n) printf("%d",n)
int main()
{
	int m, n, l, r, i, c = 0;
	s(m); s(n); s(l); s(r);
	int *a = malloc((sizeof(int)*m)), *b = malloc((sizeof(int)*n));
	for (i = 0; i < m; i++)
		s(*(a + i));
	for (i = 0; i < n; i++)
		s(*(b + i));
	int j;
	for (i = 0; i < n && j < m; i++)
	{
		while (j < m && *(b + i) < *(a + j) - l)
			j++;
		if (j<m && *(b + i)>*(a + j) + r)
			c--;
	}
	p(n - c);
	free(a);
	free(b);
	return 0;
}
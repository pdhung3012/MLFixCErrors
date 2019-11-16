#include <stdio.h>
int main()
{
	int x, yx1, x2, y1, y2, x1;//defining integers 
	float n;
	scanf("%d%d", &x, &y1);
	scanf("%d%d", &x2, &y2);
	n = (y2 - y1) / (x2 - x1);
	{   if (x1 > x2 || x1 < x2)
		printf("%0.2f", n);
	}

	{if (x1 == x2)
		printf("inf");
	}
	// Insert your code here
	return 0;
}
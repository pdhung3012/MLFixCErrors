#include <stdio.h>
int main() {
	int x1, y1, xi;// coordinates of first point
	int x2, y2;//coord for second point
	int c, d;//int varieble for further use
	float m = 0;//slope of the line
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	c = y2 - y1;
	d = x2 - x1;
	if (((x1 + x2 + y1 + y2) >= -400) && ((x1 + x2 + y1 + y2) <= 400))
	{
		if ((xi != x2) || (y1 != y2))
		{
			if (x1 == x2)
				printf("inf");
			else
			{
				m = c / d;
				printf("%.2f", m);
			}
		}
	}


	return 0;
}
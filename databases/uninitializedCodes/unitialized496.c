#include <stdio.h>
int main() {
	// Insert your code here
	int x1, x2, y1, y2;
	float slope, inf;

	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);

	slope = ((float)(y2 - y1)) / (x2 - x1);

	if (slope == -inf || slope == inf)
		printf("inf");
	else
		printf("%.2f", slope);


	return 0;
}
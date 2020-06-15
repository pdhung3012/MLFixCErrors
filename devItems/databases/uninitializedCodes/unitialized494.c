#include <stdio.h>
int main() {

	int x1, y1;
	int x2, y2, y;
	float a, b, slope;

	scanf("%d %d %d %d", &x1, &y1, &x2, &y);

	a = (y2 - y1);
	b = (x2 - x1);

	slope = a / b;

	if ((x2 - x1) != 0) {
		printf("%.2f", &slope);
	}
	else if ((x2 - x1) == 0) {
		printf("inf");
	}

	return 0;
}
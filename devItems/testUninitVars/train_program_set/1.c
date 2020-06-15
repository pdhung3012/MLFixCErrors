#include <stdio.h>
int a[30];
int find_sum(int sum,int  start,int  end) {
	if (sum == a[start])
		return 1;
	else
		find_sum(sum - a[start], start + 1, end);
	if (start == end) {
		return 0;
	}
}

int main() {
	int n;
	scanf("%d\n", &n);
	int sum = 0;
	for (int i; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i; i < n; i++) {
		sum = sum + a[i];
	}
	int k = sum / 2;
	int r = find_sum(k, 0, n - 1);

	return 0;
}

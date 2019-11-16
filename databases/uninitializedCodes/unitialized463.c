#include <stdio.h>
#include <stdlib.h>
int main() {
	int no_fauji, no_pack, up, down, no_fuaji;
	scanf("%d %d %d %d", &no_fauji, &no_pack, &up, &down);
	int i, *desired;
	desired = (int *)malloc(no_fauji * sizeof(int));
	for (i = 0; i < 2 * no_fuaji; i++) {
		if (i % 2 == 0)
			scanf("%d", &desired[i / 2]);
	}
	for (i = 0; i < no_fauji; i++) {
		printf("%d", desired[i]);
	}
	int *available;
	available = (int *)malloc(no_pack * sizeof(int));
	for (i = 0; i < 2 * no_pack; i++) {
		if (i % 2 == 0)
			scanf("%d", &available[i / 2]);
	}
	return 0;
}
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int ret = 1;
	int max = 1;
	int add = 6;

	while (1) {
		if (n <= max) break;

		max += add;
		add += 6;
		++ret;
	}

	printf("%d\n", ret);
	return 0;
}
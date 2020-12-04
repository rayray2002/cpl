#include<stdio.h>

void hanoi(int n) {
	int x;
	for (x = 1; x < (1 << n); x++)
		printf("%d -> %d\n", (x & (x - 1)) % 3, (((x | (x - 1)) + 1) % 3));
}

int main() {
	int m = 3;
	hanoi(m);
}
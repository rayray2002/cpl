#include<stdio.h>
#include<math.h>

int main() {
	int i, j;

	printf("Content-Type: text/plain;charset=utf-8\n\n");
	printf("<html><title>九九乘法表</title><body>\n");

	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++)
			printf("%d x %d =  %d  ", j, i, j * i);
		printf("\n");
	}

	printf("</body></html>");
	return 1;
}
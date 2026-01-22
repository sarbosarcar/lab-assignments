#include <stdio.h>

int main() {
	int a, b, *pa=&a, *pb=&b;
	printf("===>>");
	scanf("%d %d", pa, pb);
	int temp, *pt=&temp;
	*pt = *pa;
	*pa = *pb;
	*pb = *pt;
	printf("%d %d", *pa, *pb);
	return 0;
}

#include <stdio.h>

int main() {
	printf("Enter number of rows and cols: ");
	int r, c;
	scanf("%d %d", &r, &c);
	int arr[r*c];
	int i, j;
	for (i=0; i<r; i++) {
		for (j=0; j<c; j++) {
			printf("Element (%d, %d): ", i, j);
			scanf("%d", &arr[i*c+j]);
		}
	}
	printf("Enter indices of element to search: ");
	scanf("%d %d", &i, &j);
	printf("Element at (%d, %d) is %d\n", i, j, arr[i*c+j]);
	return 0;
}

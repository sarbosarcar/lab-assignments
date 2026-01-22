#include <stdio.h>

int main() {

	int arr[10], i=0;
	for (i; i<10; ++i) {
		printf("Enter number %d: ", i+1);
		scanf("%d", &arr[i]);
	}
	int j;
	for (i=0; i<9; i++) {
		int flag=0;
		for (j=0; j<9-i; ++j) {
			if (arr[j] < arr[j+1]) {
				int temp = arr[j];
				arr[j]  =arr[j+1];
				arr[j+1] = temp;
				flag = 1;
			}
		}
		if (!flag) { break;}
	}
	printf("Elements in descending order are::\n");
	for (i=0; i<10; i++) {
		printf("%d    ", arr[i]);
	}
	return 0;
}

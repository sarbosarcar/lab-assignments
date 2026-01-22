#include <stdio.h>

void sort(int arr[], int n) {
	int i,j,k;
	for (i=0; i<n-1; i++) {
		int flag = 0;
		for (j=i; j<n-i-1; j++) {
			if (arr[j+1]<arr[j]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		if (!flag) break;
	}
}

void print(int arr[], int n) {
	int i;
	for (i=0; i<n; i++) {
		printf("%d\t", arr[i]);
	}
}

int main() {
	int n;
	printf("Enter size of array: ");
	scanf("%d", &n);
	int arr[n], i;
	for(i=0; i<n; i++) {
		printf("Enter element %d::", i+1);
		scanf("%d", &arr[i]);
	}
	printf("Elements before sorting:\n");
	print(arr, n);
	printf("\nElements after sorting:\n");
	sort(arr, n);
	print(arr, n);
	return 0;
}


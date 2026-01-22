#include <stdio.h>

int maxarr(int arr[], int n) {
	int max=arr[0], i;
	for (i=0; i<n; i++) if (arr[i]>max) max=arr[i];
	return max;
}
int main() {
	int n;
	printf("Enter size of array:: ");
	scanf("%d", &n);
	int arr[n], i;
	for (i=0; i<n; i++) {
	printf("Enter element%d::", i+1);
	scanf("%d", &arr[i]);
	}
	int max = maxarr(arr, n);
	printf("Max element is %d", max);
	return 0;
}

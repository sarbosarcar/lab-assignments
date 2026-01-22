#include <stdio.h>

int main() {
	int n, i;
	printf("Enter number of elements:: ");
	scanf("%d", &n);
	int arr[n];
	for (i=0; i<n; i++) {
		printf("Enter element %d", i+1);
		scanf("%d", &arr[i]);
	}
	int min=arr[0], max=arr[0];
	for (i=0; i<n; i++) {
		if (arr[i]<min) min=arr[i];
		if (arr[i]>max) max=arr[i];
	}
	printf("Maximum element is %d", max);
	printf("\n Minimum element is %d", min);
	return 0;
}
		
		

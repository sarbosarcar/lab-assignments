#include <stdio.h>

int main() {
	int n;
	printf("Elements::");
	scanf("%d", &n);
	int arr[n], i=0;
	for (i; i<n;i++){
		printf("><");
		scanf("%d", &arr[i]);
	}
	int b[n];
	for (i=0;i<n;i++){
		b[i]=arr[i];
	}
	printf("{");
	for (i=0; i<n; i++){
		(i!=n-1) ? printf("%d, ", arr[i]) : printf("%d}", arr[i]);
	}
	return 0;
}


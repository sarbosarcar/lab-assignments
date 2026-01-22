#include <stdio.h>

int main() {
	int n;
	printf("Elements::");
	scanf("%d", &n);
	int arr[n];
	int i;
	for (i=0; i<n; i++) {
		printf(">");
		scanf("%d", &arr[i]);
	}
	printf("{");
	for (i=0; i<n;i++) {
		(i!=n-1) ? printf("%d, ", *(arr+i)) : printf("%d}\n", arr[i]);
	}
	return 0;
}

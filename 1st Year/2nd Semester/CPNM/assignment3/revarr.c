#include <stdio.h>

int main() {
	int n;
	printf("Elements: ");
	scanf("%d", &n);
	int i=0, arr[n];
	for (i;i<n;++i) {
		printf(">");
		scanf("%d", arr+i);
	}
	for (i=0; i<n/2;++i) {
		int temp = arr[n-i-1];
		arr[n-i-1] = arr[i];
		arr[i] = temp;
	}
	printf("{");
	for (i=0; i<n; i++)  {
		(i!=n) ? printf("%d,", arr[i]) : printf("%d}", arr[i]);
	}
	return 0;
}

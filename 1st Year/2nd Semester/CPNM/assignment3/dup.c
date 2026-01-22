#include <stdio.h>

int main() {
	int n, i, j;
	printf("Elements: ");
	scanf("%d", &n);
	int arr[n];
	for (i=0; i<n;i++) {
		printf(">");
		scanf("%d", arr+i);
	}
	int dup=0, uq=0;
	for (i=0; i<n; i++) {
		int f=0;
		for (j=0; j<i; j++) {
			if (arr[i]==arr[j]) {
				f=1;
				break;
			}
		}
		if (f==0) uq++;
		else dup++;






/*
 *
 *
 *
 *
 *
 #include <stdio.h>

int main() {
	int n;
	printf("Elements: ");
	scanf("%d", &n);
	int arr[n], i;
	for (i=0; i<n;i++) {
		printf(">");
		scanf("%d", arr+i);
	}
	int j, s_count=0,dup[9999] = {-1}; 
	for(i=0; i<n; i++){
		int el = arr[i];
		int elcount=0;
		
		for (j=0; j<n; j++) { if (arr[j]==el) elcount++; }

		if (elcount==1) s_count++;
		int c=0;
		for(j=0; j<n;j++) { if (dup[j]==el) { c=1;break;  };}
		if (c==0)  dup[i] = arr[i];
		
	}

	int dup_count = n-s_count;

	printf("{");
	for (i=n-1; i>-1; i--) {
		(i>0 && dup[i]>-1) ? printf("%d, ", dup[i]) : printf("%d }", dup[i]);
	}


	

	printf("There are %d duplicate elements", dup_count);

	return 0;
}
*/

#include <stdio.h>
#include <math.h>
void swapRows(double A[3][4], int r1, int r2) {
	int i;
	 for(i=0; i<4; ++i) {
		double temp = A[r1][i];
		A[r1][i] = A[r2][i];
		A[r2][i] = temp;
	}
}

void gauss(double A[3][4], double sol[3]) {
	int n=3, i, j, k;
	for (i=0; i<n; ++i) {
		int maxRow=i;
		for (k=i+1; k<n; k++) {
			if (fabs(A[k][i])>fabs(A[maxRow][i])) maxRow=k;
		}
		if (maxRow!=i) swapRows(A, i, maxRow);
		for (k=i+1; k<n; k++) {
			double fac = A[k][i]/ A[i][i];
			for (j=i; j<=n; j++) {
				A[k][j] -= fac*A[i][j];
			}
		}
	}
	for (i=n-1; i>=0; i--) {
		sol[i]=A[i][n];
		for (j=i+1; j<n; ++j) sol[i]-=A[i][j]*sol[j];
		sol[i]/=A[i][i];
	}
}
void gaussjordan(double A[3][4], double sol[3]) {
	int n=3; int j, i, k;
	for(i=0; i<n; i++) { int maxRow=i;
	for (k=i+1; k<n; k++) {
		if (fabs(A[k][i])>fabs(A[maxRow][i])) {
			maxRow=k;}}
	if (maxRow!=i){swapRows(A, i, maxRow);}
	double pivot=A[i][i];
	if (pivot!=0){for(j=0; j<=n; j++) A[i][j]/=pivot;}
	for (k=0; k<n; k++) {
		if (k!=i) {
			double fac=A[k][i];
			for (j=0; j<=n; j++) {A[k][j]-=fac*A[i][j];}}}}
	for (i=0; i<n; i++) sol[i]=A[i][n];
	}
int main() {
	double A[3][4]={1,1,1,3,2,3,1,6,1,-1,-1,-3};
	double sol[3];
	printf("Enter option\n1.Gaussian Elimination\n2.Gauss Jordan ::");
	int y;
	scanf("%d", &y);
	if (y==1) gauss(A,sol);
	else if (y==2) gaussjordan(A, sol);
	int i;
	for (i=0; i<3; i++) {
		printf("x%d=%.2f\n", i+1, sol[i]);
	}
	return 0;
}

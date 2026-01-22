#include <stdio.h>
#include <math.h>

void swapRows(double A[3][6], int r1, int r2) {
	int i;
	for(i=0; i<6; ++i) {
		double temp = A[r1][i]; 
		A[r1][i]=A[r2][i];
		A[r2][i]=temp;
	}
}
void inverse(double A[3][3], double inv[3][3]) {
	double aug[3][6];
	int i,j,k;
	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			aug[i][j]=A[i][j];
			aug[i][j+3]=(i==j)?1.0 : 0.0;
			}}
	for (i=0; i<3; i++) {
	int maxRow=i; 
	for(k=i+1; k<3; k++) {
	if (fabs(aug[k][i])>fabs(aug[maxRow][i])){
	maxRow=k;
}}
	if (maxRow!=i) swapRows(aug, i, maxRow);
	double pivot=aug[i][i];
	for (j=0; j<6; j++) aug[i][j]/=pivot;
	for (k=0; k<3; k++) {if (k!=i) {double fac=aug[k][i];
	for (j=0; j<6; j++){aug[k][j]-=fac*aug[i][j];}}}}
	for(i=0; i<3; i++) {for (j=0; j<3; j++) {inv[i][j]=aug[i][j+3];
}}}
void mul(double A[3][3], double vec[3], double res[3]) {
int i, j;
	for (i=0; i<3; i++) 
{	res[i]=0;
	for (j=0; j<3; j++) {
		res[i]+=A[i][j]*vec[j];
	}}}
int main() {
	double A[3][3]={1,1,1,1,1,-1,1,-1,1};
	double rhs[3]={6,0,2};
	double inv[3][3];
	double sol[3];
	inverse(A, inv);	
	mul(inv, rhs, sol);
	int i;
for (i=0; i<3; i++ ){
printf("x%d=%.2f\n", i+1, sol[i]);
}
return 0;
}

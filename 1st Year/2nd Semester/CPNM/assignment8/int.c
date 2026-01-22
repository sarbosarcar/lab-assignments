#include <stdio.h>


double f(float x) {
	return (double) 1/(1+x);
}

double trap(int a, int b, int n) {
	double step = (b-a)/n;

	double sum=0; int i;
	for (i=a; i<=b; i+=step) {
		sum+=(i!=a && i!=b) ? f(i)*2 : f(i);
		
	}
	double t;
	t = (step/2)*sum;
	
	return t;
}

double simpson(int a, int b, int n) {
	double step = (b-a)/n;
	int i; double sum;
	for(i=0; i<=n; i++) {
		if (i!=0 && i!=n) {
			sum+=(i%2==0) ? 2*f(a+i*step) : 4*f(a+i*step);
		}
		else {
 			sum+=f(a+i*step);
		}
	}
	return (double) (step/3)*(sum);
}

int main() {
	int a=0, b=6, n=6;
	double trapint = trap(a, b, n), simint = simpson(a, b, n);
	printf("Using Trapezoidal rule, ans is %lf\n Using Simpson 1/3 rule, ans is %lf", trapint, simint);
	return 0;
}
	

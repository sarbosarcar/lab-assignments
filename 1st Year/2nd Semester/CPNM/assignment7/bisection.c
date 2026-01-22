#include <stdio.h>
#include <math.h>

double bisection(double, double);
double f(double);


double bisection(double a, double b) {

	double fa =f(a); //find f(a), f(b)
	double fb =f(b); 
	
	if (fa*fb<0) { //if f(a)f(b)<0
		double mid = (a+b)/2; //c=(a+b)/2
		double val = f(mid); //f(c)
		
		if (fabs(val-fa*fb)<0.0001) {
			return mid; //correct till 4 dps
		}
		else {
			if (fa<0 && val>0) return bisection(a, mid); //new c between a and mid
			else return bisection(mid, b); //c between mid and b
		}
	}
}

double f(double x) {
	return pow(x, 3)+pow(x,2)-1;
}		
			

int main() {
	double  a, b;
	printf("Enter values for a and b");
	scanf("%lf %lf", &a, &b);
	
	printf("One root is %.4lf", bisection(a, b));	
	return 0;
}


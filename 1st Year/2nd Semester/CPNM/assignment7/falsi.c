#include <stdio.h>
#include <math.h>

double f(double);

double falsi(double, double);

double f(double x) {
	return pow(x, 3)-9*x+1;
}

double falsi(double a, double b) {
	double fa = f(a), fb = f(b);
	if (fa*fb<0) {
		double c = (fa*b-a*fb)/(fa-fb), fc = f(c);
		if (fabs(fc-fa*fb)<0.000001) return c;
		else {
			if (fc > 0) return falsi(a, c);	
			else return falsi(c, b);
		}
	}
}

int main() {
double a, b;
printf("Enter the values for a &b ::");
scanf("%lf %lf", &a, &b);	
printf("One of the roots is %g\n", falsi(a, b));
	return 0;
}

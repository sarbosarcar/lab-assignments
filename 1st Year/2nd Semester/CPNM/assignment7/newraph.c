#include <stdio.h>
#include <math.h>

double f(double);
double fd(double);
double newtonraphson(double);

double f(double x) {
	return pow(x, 3)+8*x-4;
}

double fd(double x) {
	return 3*x*x+8;
}

double newtonraphson(double prev) {
	double next = prev - (f(prev))/(fd(prev));
	double prevval = f(prev), nextval = f(next);
	if (fabs(prev-next)<0.000001) return next;
	else return newtonraphson(next);
}

int main() {
	double x0;
	printf("Enter initial value:: ");
	scanf("%lf", &x0);
	printf("One root is %.6lf", newtonraphson(x0));
	return 0;
}

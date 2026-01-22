#include <stdio.h>

int main () {
	int y;
	do {
	printf("\t\tMENU\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Exit\n Enter an option: ");
	scanf("%d", &y);
	if (y!=5) {
	float a, b;
	printf("Enter two operands: ");
	scanf("%f %f", &a, &b);
	switch (y) {
	
	case 1:
		printf("Sum is %g \n", a+b);
		break;
	case 2: 
		printf("Difference is %g \n", a-b);
		break;
	case 3:
		printf("Product is %g \n", a*b);
		break;
	case 4:
		(b!=0) ? printf("Quotient is %g \n", a/b) : printf("Divison by 0!\n");
		break;
	default: printf("Invalid value!\n");

	}
	}
else {
break;
}	
	} while (y!=5);
return 0;
}

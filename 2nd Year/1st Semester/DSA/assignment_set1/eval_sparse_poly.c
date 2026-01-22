#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct term {
    float coeff;
    int expo;
} term;

typedef struct poly {
    int n;
    term a[1000];
} poly;

int main() {
    
    int n, i, j, k, l;
    printf("Enter number of terms in the polynomial: ");
    scanf("%d", &n);
    poly *p = (poly*) malloc(sizeof(poly));
    p->n = n;
    printf("Enter coefficients and exponents of terms in polynomial:\n");
    for (i=0; i<n; i++) {
        float c; int e;
        printf("> ");
        scanf("%f %d", &c, &e);
        term t = {c, e};
        p->a[i] = t;
    }
    printf("Enter value of x to evaluate: ");
    float x;
    scanf("%f", &x);
    float sum=0;
    for (i=0; i<p->n; i++) {
        sum += (pow(x,p->a[i].expo)*p->a[i].coeff);
    }
    printf("Polynomial: ");
    for (i=0; i<p->n; i++) printf("%+gx^%d", p->a[i].coeff, p->a[i].expo);
    printf("\nEvaluated value at x=%g is %g", x, sum);
    free(p);
    return 0;
}

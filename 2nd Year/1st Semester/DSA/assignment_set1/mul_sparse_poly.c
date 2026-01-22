#include <stdio.h>
#include <stdlib.h>

typedef struct term {
    float coeff;
    int expo;
} term;

typedef struct poly {
    int n;
    term a[1000];
} poly;


void addTerm(poly *p, float c, int e) {
    int i;
    for (i = 0; i < p->n; i++) {
        if (p->a[i].expo == e) {
            p->a[i].coeff += c;
            return;
        }
    }
    p->a[p->n].coeff = c;
    p->a[p->n].expo = e;
    p->n++;
}

int main() {
    int n1, n2, i, j;
    printf("Enter number of terms in the 1st polynomial: ");
    scanf("%d", &n1);
    printf("Enter number of terms in the 2nd polynomial: ");
    scanf("%d", &n2);
    
    poly *p1 = (poly*) malloc(sizeof(poly));
    poly *p2 = (poly*) malloc(sizeof(poly));
    poly *p3 = (poly*) malloc(sizeof(poly)); 

    p1->n = n1;
    p2->n = n2;
    p3->n = 0; 

    printf("Enter coefficients and exponents of terms in polynomial 1:\n");
    for (i = 0; i < n1; i++) {
        float c;
        int e;
        printf("> ");
        scanf("%f %d", &c, &e);
        term t = {c, e};
        p1->a[i] = t;
    }

    printf("Enter coefficients and exponents of terms in polynomial 2:\n");
    for (i = 0; i < n2; i++) {
        float c;
        int e;
        printf("> ");
        scanf("%f %d", &c, &e);
        term t = {c, e};
        p2->a[i] = t;
    }

    // Multiply polynomials
    for (i = 0; i < p1->n; i++) {
        for (j = 0; j < p2->n; j++) {
            float coeff = p1->a[i].coeff * p2->a[j].coeff;
            int expo = p1->a[i].expo + p2->a[j].expo;
            addTerm(p3, coeff, expo);
        }
    }

    // Print polynomials
    printf("Polynomial 1: ");
    for (i = 0; i < p1->n; i++) {
        printf("%+gx^%d", p1->a[i].coeff, p1->a[i].expo);
    }
    printf("\n");

    printf("Polynomial 2: ");
    for (i = 0; i < p2->n; i++) {
        printf("%+gx^%d", p2->a[i].coeff, p2->a[i].expo);
    }
    printf("\n");

    // Print result of multiplication
    printf("Multiplication: ");
    for (i = 0; i < p3->n; i++) {
        printf("%+gx^%d", p3->a[i].coeff, p3->a[i].expo);
    }
    printf("\n");

    // Free allocated memory
    free(p1);
    free(p2);
    free(p3);

    return 0;
}


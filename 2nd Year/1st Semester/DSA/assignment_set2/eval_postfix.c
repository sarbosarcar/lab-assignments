#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
	int val;
	struct node* next;
} node;

typedef struct stack {
	node *top;
} stack;

void push(stack *s, int v) {
	node *temp = (node*) malloc(sizeof(node));
	temp->val = v;
	temp->next = s->top;
	s->top = temp;
}

int isEmpty(stack *s) {
	if (s->top) return 0;
	return 1;
}

int pop(stack *s) {
	if (isEmpty(s)) return -1;
	else {
		node* tp = s->top;
		int v = tp->val;
		s->top = s->top->next;
		free(tp);
		return v;
	}
}

void print(stack *s) {
	if (!isEmpty(s)) {
		node *t = s->top;
		while (t) {
			printf("%d\t", t->val);
			t = t->next;
		}
	}
	printf("\n");
}

void eval(char *exp) {
	int i,j,k,l;
	stack *s = (stack*)malloc(sizeof(stack));
	s->top = NULL;
	printf("Operand stack after each iteration: \n");
	for (i=0; exp[i]!='\0' && exp[i]!='\n'; i++) {
		if (0<=(exp[i]-'0') && 9>=(exp[i]-'0')) {
			push(s, exp[i]-'0');
		}
		else {
			char op = exp[i];
			int op1 = pop(s);
			int op2 = pop(s);
			switch (op) {
				case '+':
					push(s, op2+op1);
					break;
				case '-':
					push(s, op2-op1);
					break;
				case '/':
					push(s, op2/op1);
					break;
				case '*':
					push(s, op2*op1);
					break;
				case '^':
					push(s, pow(op2,op1));
					break;
			}
		}
		print(s);
	}
	printf("Result is %d\n", pop(s));
}

int main() {
	char tmp[10000];
	printf("Enter expression: ");
	fgets(tmp, 10000, stdin);
	eval(tmp);
	return 0;
}

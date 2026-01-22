#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct node {
	int val;
	struct node *next;
} node;

typedef struct stack {
	node *top;
} stack;

void create(stack *s) {
	s->top = NULL;
}

void push(stack *s, int val) {
	node *tmp = (node*) malloc(sizeof(node*));
	tmp->val = val;
	tmp->next = s->top;
	s->top = tmp;
}

int pop(stack *s) {
	if (s->top) {
		int data = s->top->val;
		s->top = s->top->next;
		return data;
	}
	else {
		printf("Underflow!\n");
		return -1;
	}
}

int isEmpty(stack *s) {
	if (!s->top) return 1;
	else return 0;
}

void print(stack *s) {
	if (!isEmpty(s)) {
		node *tmp = s->top;
		while (tmp) {
			printf("%d\t", tmp->val);
			tmp=tmp->next;
		}
	}
	else
		printf("Empty Stack!");
	printf("\n");
}

int main() {
	printf("Initialising a stack!\n");
	stack *s = (stack*) malloc(sizeof(stack*));
	create(s);
	int c = 0, n, z;
	do {
		printf("\t\tMENU\n1. Push\n2. Pop\n3. Check if empty\n4. Print\n5. Exit\nEnter your choice:: ");
		scanf("%d", &c);
		switch (c) {
			case 1:
				printf("Enter value to push: ");
				scanf("%d", &n);
				push(s, n);
				break;
			case 2:
				z = pop(s);
				if (z!=-1) printf("Popped element is %d\n", z);
				break;
			case 3:
				if (isEmpty(s)) printf("Stack is empty!\n");
				else printf("Not Empty!\n");
				break;
			case 4:
				print(s);
				break;
			case 5:
				break;
		}
	
	} while(c!=5);
	printf("Exiting...\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char val;
	struct Node* next;
} Node;

typedef struct Stack {
	Node* top;
} Stack;

void push(Stack *s, char val) {
	Node* new = (Node*) malloc(sizeof(Node*));
	new->val = val;
	new->next = s->top;
	s->top = new;
}

char pop(Stack *s) {
	char d = s->top->val;
	if (s->top) {
	Node *temp = s->top;
	if (s->top->next) s->top = s->top->next;
	else s->top = NULL;
	free(temp);
	return d;
	}
	else return '0';
}

int prec(char c) {
	if (c=='(' || c==')') return 0;
	else if (c=='^') return 3;
	else if (c=='*' || c=='/') return 2;
	else if (c=='+' || c=='-') return 1;
	else return 0;
}



/*
int isoperator(char);

void insert(char arr[1000], int n, int i, char k) {
	int j=n;
	while (j>i) {
		arr[j] = arr[j-1];
		j--;
	}
	arr[i] = k;
}

int parenthesize(char arr[1000], int n) {
	int i,j,k;
	j=0;
	while (i<n) {
		if (isoperator(arr[i])) {
				if (arr[i]=='*' || arr[i]=='/') {
					insert(arr, n, i-j, '(');
					j++;
					insert(arr, n, i, arr[i]);
					j++;
					insert(arr, n, i+j, ')');
					j++;
				}
				else if (arr[i]=='+' || arr[i]=='-') {
					insert(arr, n, i-j, '(');
					j++;
					insert(arr, n, i, arr[i]);
					j++;
					insert(arr, n, i+j, ')');
					j++;
				}
				
		}
		else {
			insert(arr, n, i, arr[i]);
			j++;
		}
		i++;
	}
	return i;
}
*/
int isoperator(char c) {
	if ((c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='(' || c==')')) return 1;
	return 0;
}

int associativity(char op) {
	if (op=='^') return 1;
	return 0;
}

void print(Stack *s) {
	Stack *temp = s;
	while (temp->top) {
		printf("%c\t", temp->top->val);
		temp->top = temp->top->next;
	}
	printf("\n");
}

int main() {
	char temp[1000];
	printf("Enter expression: ");
	fgets(temp, 1000, stdin);
	int i,j,k,l;
	Stack *opstack = (Stack*) malloc(sizeof(Stack*));
	opstack->top = NULL;
	char res[1000];
	j=0;
	for (i=0; temp[i]!='\0'; i++) {
		if (isoperator(temp[i])) {
			if (!opstack->top) {
			push(opstack, temp[i]);
			}
		
			else {
				if (prec(opstack->top->val) > prec(temp[i])) {
					if (temp[i]!=')' && temp[i]!='(') {
					char op = pop(opstack);
					res[j++] = op;
					push(opstack, temp[i]);
					}
					else if (temp[i]=='(') {
						push(opstack, temp[i]);
					}
					else {
						res[j++] = pop(opstack);
						pop(opstack);	
					}
				}
				
				else if (prec(opstack->top->val) <= prec(temp[i])) {
					push(opstack, temp[i]);
				}
			}
		}
		else {
			res[j++] = temp[i];
		}
	}
	j--;
	while (opstack->top) {
		res[j++] = pop(opstack);
	}
	res[j] = '\0';
	printf("%s\n", res);
	return 0;
}















/*
int main() {
	int n,i,j,k,l;
	printf("Enter length of expression: ");
	scanf("%d", &n);
	char temp[1000];
	printf("Enter expression: ");
	scanf("%s", temp);
	i=0; j=0; k=0;
	char arr[1000];
	char res[1000];
	printf("%s\n", temp);

	while (i<n) {
		if (isoperator(temp[i])) {
			arr[j] = temp[i];
			j++;
		}
		else if (temp[i]==')') {
			res[k] = arr[j-1];
			j--;
			k++;
		}
		else {
			res[k] = temp[i];
			k++;
		}
		i++;
	}

	for (l=0; l<k; l++) {
		if (res[l] != '(')
		printf("%c", res[l]);
	}
	printf("\n");
	return 0;
}
*/

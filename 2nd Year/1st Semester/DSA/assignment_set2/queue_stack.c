#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
        int data;
        struct stack *next;
} stack;

typedef struct queue {
        stack *stack1, *stack2;
} queue;

stack* push(stack *s, int val) {
        stack *newnode = (stack*)malloc(sizeof(stack));
        newnode->data = val;
        newnode->next = s;
        return newnode;
}

int pop(stack **s) {
        if (!*s) return -1;
        stack *temp = *s;
        int val = temp->data;
        *s = temp->next;
        free(temp);
        return val;
}

int peek(stack *s) {
        if (!s) return -1;
        return s->data;
}

int empty(stack *s) {
        return s == NULL;
}

queue* create() {
        queue *q = (queue*)malloc(sizeof(queue));
        q->stack1 = q->stack2 = NULL;
        return q;
}

void enqueue(queue *q, int val) {
        q->stack1 = push(q->stack1, val);
}

int dequeue(queue *q) {
        if (empty(q->stack2)) {
                while (!empty(q->stack1)) {
                        q->stack2 = push(q->stack2, pop(&q->stack1));
                }
        }
        return pop(&q->stack2);
}

int front(queue *q) {
        if (!empty(q->stack2)) return peek(q->stack2);
        if (!empty(q->stack1)) return peek(q->stack1);
        return -1;
}

int count(queue *q) {
        int count = 0;
        stack *temp = q->stack1;
        while (temp) {
                count++;
                temp = temp->next;
        }
        temp = q->stack2;
        while (temp) {
                count++;
                temp = temp->next;
        }
        return count;
}

int main() {
        int c = 0;
        queue *q = create();
        do {
                printf("\t\tMENU\n1. Construct a queue\n2. Insert an element\n3. Delete an element\n4. Count no. of elements\n5. Exit\n");
                printf("Enter an option: ");
                scanf("%d", &c);
                if (c == 1) {
                        printf("Successfully created a queue!\n");
                }
                else if (c == 2) {
                        int v;
                        printf("Enter value to insert: ");
                        scanf("%d", &v);
                        enqueue(q, v);
                        printf("Successfully inserted element\n");
                }
                else if (c == 3) {
                        int r = dequeue(q);
                        if (r >= 0) printf("Successfully deleted element: %d!\n", r);
                        else printf("Could not delete any element!\n");
                }
                else if (c == 4) {
                        int ct = count(q);
                        printf("There are %d elements\n", ct);
                }
                else if (c == 5) {
                        printf("Exiting...\n");
                }
                else {
                        printf("Invalid choice!\n");
                }
        } while (c != 5);
        return 0;
}


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
        int data;
        struct node *next;
} node;

typedef struct queue {
        node *front, *rear;
} queue;

int overflow(queue* q);
int underflow(queue* q);

int enqueue(queue *q, int v) {
        node *newnode = (node*)malloc(sizeof(node));
        if (!newnode) return 0;
        newnode->data = v;
        if (!q->front) {
                q->front = q->rear = newnode;
                q->rear->next = q->front;
        } else {
                q->rear->next = newnode;
                q->rear = newnode;
                q->rear->next = q->front;
        }
        return 1;
}

int dequeue(queue *q) {
        if (underflow(q)) return -1;
        int val;
        if (q->front == q->rear) {
                val = q->front->data;
                free(q->front);
                q->front = q->rear = NULL;
        } else {
                node *temp = q->front;
                val = temp->data;
                q->front = q->front->next;
                q->rear->next = q->front;
                free(temp);
        }
        return val;
}

int count(queue *q) {
        if (!q->front) return 0;
        int c = 1;
        node *temp = q->front;
        while (temp->next != q->front) {
                temp = temp->next;
                c++;
        }
        return c;
}

int overflow(queue *q) {
        return 0;
}

int underflow(queue *q) {
        return q->front == NULL;
}

queue *create() {
        queue *q = (queue*) malloc(sizeof(queue));
        q->front = q->rear = NULL;
        return q;
}

int main() {
        int c = 0;
        queue *q = create();
        do {
                printf("\t\tMENU\n1. Construct a queue\n2. Insert an element\n3. Delete an element\n4. Count no. of elements\n5. Check for overflow\n6. Check for underflow\n7. Exit\n");
                printf("Enter an option: ");
                scanf("%d", &c);
                if (c == 1) {
                        printf("Successfully created a queue!\n");
                }
                else if (c == 2) {
                        int v;
                        printf("Enter value to insert: ");
                        scanf("%d", &v);
                        int r = enqueue(q, v);
                        if (r) printf("Successfully inserted element\n");
                        else printf("Could not insert element\n");
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
                        if (overflow(q)) printf("Overflow!\n");
                        else printf("Not Overflow!\n");
                }
                else if (c == 6) {
                        if (underflow(q)) printf("Underflow!\n");
                        else printf("Not Underflow!\n");
                }
                else if (c == 7) {
                        printf("Exiting...\n");
                }
                else {
                        printf("Invalid choice!\n");
                }
        } while (c != 7);
        return 0;
}


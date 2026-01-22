#include <stdio.h>
#include <stdlib.h>

typedef struct bst {
        int val;
        struct bst *left, *right;
} bst;

bst* createnode(int x) {
        bst *t = malloc(sizeof(bst));
        t->val=x;
        t->left = t->right = NULL;
        return t;
}

bst* search(bst *root, int k) {
        if (!root) {
                printf("Not found!\n");
                return NULL;
        }
        else if (k<root->val) {
                return search(root->left, k);
        }
        else if (k>root->val) {
                return search(root->right, k);
        }
        else {
                printf("Found element!\n");
                return root;
        }
}

bst* ios(bst* root) {
        bst *curr = root, *succ=NULL;
        if (curr->right) {
                succ=curr->right;
                while (succ->left) {
                        succ=succ->left;
                }
        }
        return succ;
}

bst* iop(bst* root) {
        bst *curr=root, *pred=NULL;
        if (curr->left) {
                pred=curr->left;
                while (pred->right) {
                        pred=pred->right;
                }
        }
        return pred;
}

void insert(bst* root, bst* k) {
        if (k->val<root->val) {
                if (root->left) insert(root->left, k);
                else root->left = k;
        }
        else if (k->val>root->val) {
                if (root->right) insert(root->right, k);
                else root->right = k;
        }
}

bst* delete(bst *root, int k) {
        if (!root) return root;
        if (k<root->val) root->left = delete(root->left, k);
        else if (k>root->val) root->right = delete(root->right, k);
        else {
                if (!root->left) {
                        bst *temp = root->right;
                        free(root);
                        return temp;
                }
                else if (!root->right) {
                        bst *temp = root->left;
                        free(root);
                        return temp;
                }
                bst *t = ios(root);
                root->val = t->val;
                root->right = delete(root->right, t->val);
        }
        return root;
}

void io(bst *root) {
        if (!root) return;
        io(root->left);
        printf("%d->", root->val);
        io(root->right);
}

int main() {
        bst* root = NULL;
        int c=0, z=0;
        do {
                printf("\t\tMENU\n1.Create\n2.Insert\n3.Delete\n4.IO Successor\n5.IO Predecessor\n6.Search\n7.View Tree\n8.Exit\n");
                printf("Enter a choice: ");
                scanf("%d", &c);
                switch (c) {
                        case 1:
                                root = createnode(7);
                                insert(root, createnode(5));
                                insert(root, createnode(9));
                                insert(root, createnode(14));
                                break;
                        case 2:
                                printf("Enter value to insert: ");
                                scanf("%d", &z);
                                if (root) insert(root, createnode(z));
                                else root = createnode(z);
                                break;
                        case 3:
                                printf("Enter value to delete: ");
                                scanf("%d", &z);
                                root = delete(root, z);
                                break;
                        case 4:
                                printf("Enter value to check: ");
                                scanf("%d", &z);
                                bst* tmp = search(root, z);
                                if (tmp) {
                                        bst* succ = ios(tmp);
                                        if (succ) printf("IO Successor is %d\n", succ->val);
                                        else printf("No Successor\n");
                                }
                                break;
                        case 5:
                                printf("Enter value to check: ");
                                scanf("%d", &z);
                                bst* tmp2 = search(root, z);
                                if (tmp2) {
                                        bst* pred = iop(tmp2);
                                        if (pred) printf("IO Predecessor is %d\n", pred->val);
                                        else printf("No Predecessor\n");
                                }
                                break;
                        case 6:
                                printf("Enter value to check: ");
                                scanf("%d", &z);
                                search(root, z);
                                break;
                        case 7:
                                if (root) io(root);
                                else printf("Tree is empty!\n");
                                break;
                        case 8:
                                break;
                        default:
                                printf("Invalid choice!\n");
                }
        } while (c!=8);
        printf("Exiting!...\n");
        return 0;
}


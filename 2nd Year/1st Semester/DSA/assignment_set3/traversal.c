#include <stdio.h>
#include <stdlib.h>

typedef struct btree {
    int val;
    struct btree *left, *right;
} btree;

void inorder(btree *b) {
    if (b) {
        inorder(b->left);
        printf("%d ", b->val);
        inorder(b->right);
    }
}

void preorder(btree *b) {
    if (b) {
        printf("%d ", b->val);
        preorder(b->left);
        preorder(b->right);
    }
}

void postorder(btree *b) {
    if (b) {
        postorder(b->left);
        postorder(b->right);
        printf("%d ", b->val);
    }
}


int main()
{
    int c=0;
    
        btree *root = NULL;
        btree *b = (btree*) malloc(sizeof(btree));
    do {
        printf("\t\tMENU\n1.Create\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\n");
        scanf("%d", &c);
        switch (c) {
            case 1:
                b->val = 1;
                b->left = b->right = NULL;
                root=b;
                b = (btree*) malloc(sizeof(btree));
                b->val = 2;
                b->left = b->right = NULL;
                root->left = b;
                b = (btree*) malloc(sizeof(btree));
                b->val = 3;
                b->left = b->right = NULL;
                root->right = b;
                printf("done\n");
                break;
            case 2:
                if (root)
                inorder(root);
                break;
            case 3:
                if (root)
                preorder(root);
                break;
            case 4: 
                if (root)
                postorder(root);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice!\n");
        } 
    } while (c!=5);
    return 0;
}

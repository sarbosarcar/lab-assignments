#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(int inorder[], int preorder[], int* preIndex, int start, int end) {
    if (start > end)
        return NULL;
    int current = preorder[*preIndex];
    (*preIndex)++;
    Node* node = newNode(current);

    if (start == end)
        return node;

    int inIndex = search(inorder, start, end, current);

    node->left = buildTree(inorder, preorder, preIndex, start, inIndex - 1);
    node->right = buildTree(inorder, preorder, preIndex, inIndex + 1, end);

    return node;
}

void printInorder(struct Node* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    int inorder[] = {2, 1, 7, 9, 4, 11, 2, 6};
    int preorder[] = {7, 1, 2, 2, 4, 9, 11, 6};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    int preIndex = 0;

    struct Node* root = buildTree(inorder, preorder, &preIndex, 0, n - 1);

    printf("Inorder traversal of the constructed tree: ");
    printInorder(root);
    printf("\n");

    return 0;
}


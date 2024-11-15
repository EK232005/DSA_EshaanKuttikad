#include <stdio.h>
#include <stdlib.h>
#define max_nodes 1000

struct binary_tree_node {
    int data;
    struct binary_tree_node *left, *right;
};

typedef struct binary_tree_node btn;

void preorder_traversal_iterative(btn* root) {
    if (root == NULL) { // if root argument is an empty node
        printf("Empty Binary Tree...\n");
        return;
    }

    btn* stack[max_nodes];
    int top = 0;
    stack[top++] = root; // push root onto the stack

    while (top > 0) {
        btn* current = stack[--top]; // pop from stack
        printf("%d -> ", current->data);

        // Push right child first, so the left child is processed first
        if (current->right != NULL) {
            stack[top++] = current->right;
        }
        if (current->left != NULL) {
            stack[top++] = current->left;
        }
    }
    printf("\n");
}

void inorder_traversal_iterative(btn* root) {
    btn* stack[max_nodes];
    int top = -1;
    btn* current = root;

    while (current != NULL || top >= 0) {
        // Traverse to the leftmost node, pushing all nodes along the way
        while (current != NULL) {
            stack[++top] = current;  // push current node onto stack
            current = current->left;
        }

        // Pop the top node and visit it
        current = stack[top--];
        printf("%d -> ", current->data);  // process the current node

        // Move to the right subtree
        current = current->right;
    }
    printf("\n");
}

int main() {
    // Allocate memory for nodes
    btn *root = (btn*)malloc(sizeof(btn));
    btn *A = (btn*)malloc(sizeof(btn));
    btn *B = (btn*)malloc(sizeof(btn));
    btn *C = (btn*)malloc(sizeof(btn));

    // Initialize node data
    root->data = 0;
    A->data = 1;
    B->data = 2;
    C->data = 3;

    // Set up tree structure
    root->left = A;
    root->right = B;
    A->left = C;
    A->right = NULL;
    B->left = B->right = NULL;
    C->left = C->right = NULL;

    printf("Preorder Traversal:  ");
    preorder_traversal_iterative(root);
    printf("Inorder Traversal:  ");
    inorder_traversal_iterative(root);

    // Free allocated memory
    free(root);
    free(A);
    free(B);
    free(C);

    return 0;
}

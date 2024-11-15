#include <stdio.h>
#include <stdlib.h>

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

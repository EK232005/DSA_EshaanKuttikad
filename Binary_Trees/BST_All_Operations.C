/*
1. createBST() – This function should create a ROOT pointer with NULL value as empty BST.
3. typedef search(typedef element ) – This function should search for specified element on the non-empty BST and return a pointer to it.
4. typedef delete(typedef element)  – This function searches for an element and if found deletes it from the BST and returns the same.
5. typedef getParent(typedef element) - This function searches for an element and if found, returns its parent element.
6. DisplayInorder( ) – This is a void function which should go through non- empty BST, traverse it in inorder fashion and print the elements on the way.
*/

/*
Functions that are added:
1- createBST
2- insertBST
*/
#include <stdio.h>
#include <stdlib.h>

struct Binary_Tree{
    int key;
    struct Binary_Tree *left, *right;
};

typedef struct Binary_Tree bst;

bst* createnewnode(int value){ //supporting function
    bst *node = (bst*)malloc(sizeof(bst));
    node->key = value;
    return node;
}

bst* createBST(){
    bst *newbst = (bst*)malloc(sizeof(bst)); //root pointer
    if(newbst == NULL){
        printf("failed to create binary tree structure...\n");
        return NULL;
    }
    newbst->key = 0;
    return newbst;
}

bst* insertBST(bst* node, int value){ //insertBST
    if(node==NULL){
        bst *newnode = createnewnode(value);
        return newnode;
    }
    else{
        if(value > node->key){
            insertBST(node->right, value);
        }
        else{
            insertBST(node->left, value);
        }
    }
    return node;
}

int main(){
    bst* rootNode = createBST();
    insertBST(rootNode, 10);
    return 1;
}

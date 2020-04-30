#include<stdio.h>
#include <stdlib.h>
#define COUNT 10

struct Node {
    int data;
    struct Node* left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void print2DUtil(struct Node *root, int space) {
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    print2DUtil(root->left, space);
}

void print2D(struct Node *root) {
    print2DUtil(root, 0);
}

int main() {
    struct Node *root = newNode(49);
    root->left = newNode(28);
    root->right = newNode(83);

    root->left->left = newNode(18);
    root->left->right = newNode(40);
    root->right->left = newNode(71);
    root->right->right = newNode(97);

    root->left->left->left = newNode(11);
    root->left->left->right = newNode(19);
    root->left->right->left = newNode(32);
    root->left->right->right = newNode(44);
    root->right->left->left = newNode(69);
    root->right->left->right = newNode(72);
    root->right->right->left = newNode(92);
    root->right->right->right = newNode(99);

    print2D(root);

    return 0;
}


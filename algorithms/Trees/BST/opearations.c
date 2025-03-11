#include <stdio.h>

// ---- Node Structure Definition ----
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int getHeight(Node* root)
{
    if(root == NULL)
    {
        return -1;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int getSize(Node* root)
{
    if(root == NULL) return 0;

    return 1 + getSize(root->left) + getSize(root->right);
}

int findMaxValue(Node* root){
    if(root == NULL) return -1;

    while(root->right != NULL){
        root = root->right;
    }

    return root->data;
}

int findMinValue(Node* root){
    if(root == NULL) return -1;

    while(root->left != NULL){
        root = root->left;
    }

    return root->data;
}

Node* mirrorTree(Node* root)
{
    if(root == NULL) return NULL;

    // swap left and right children's
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // recursively mirror the left and right subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);

    return root;
}

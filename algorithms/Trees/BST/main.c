#include <stdio.h>
#include <stdlib.h>

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

// Advanced tree printing function
void printTree(Node* root, int space, int indent) {
    // Base case
    if (!root) return;

    // Increase distance between levels
    space += indent;

    // Process right child first (will appear at the top)
    printTree(root->right, space, indent);

    // Print current node
    printf("\n");
    for (int i = indent; i < space; i++) {
        printf(" ");
    }

    // Print the value and a branch indicator
    printf("%d", root->data);
    if (root->right || root->left) printf("─┐");

    // Process left child (will appear at the bottom)
    printTree(root->left, space, indent);
}

void printBST(Node* root) {
    printf("Tree Structure:");
    printTree(root, 0, 4);
    printf("\n\n");
}

Node* insert(Node* root, int data)
{
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

Node* search(Node* root, int value)
{
    // Base case: root is NULL or value is found
    if (root == NULL || root->data == value)
        return root;

    // Value is greater than root's value
    if (root->data < value)
        return search(root->right, value);

    // Value is smaller than root's value
    return search(root->left, value);
}

// Free allocated memory (added memory management)
void freeTree(Node* node) {
    if (node == NULL) return;
    // Recursively free children
    freeTree(node->left);
    freeTree(node->right);
    // Free the node itself
    free(node);
}

// ---- Main Function ----
int main()
{
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 10);

    // Print the tree structure
    printBST(root);

    int value = 40;
    Node* result = search(root, value);
    if (result != NULL)
    {
        printf("Value %d found in the tree.\n", value);
    }
    else
    {
        printf("Value %d not found in the tree.\n", value);
    }

    // Call the cleanup function before exit
    freeTree(root);

    return 0;
}

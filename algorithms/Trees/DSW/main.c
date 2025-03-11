#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // For log2 function

// Define the structure of a BST node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Function to insert a node in BST
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// First part: Tree to Vine
int treeToVine(Node* root) {
    int nodeCount = 0;
    Node* tail = root;
    Node* rest = tail->right;

    while (rest != NULL) {
        if (rest->left == NULL) {
            // Move tail down one level
            tail = rest;
            rest = rest->right;
            nodeCount++;
        } else {
            // Rotate right child up
            Node* temp = rest->left;
            rest->left = temp->right;
            temp->right = rest;
            rest = temp;
            tail->right = temp;
        }
    }

    return nodeCount + 1; // +1 for the root
}

// Helper function to perform rotations (compression)
void compression(Node* root, int count) {
    Node* scanner = root;

    for (int i = 0; i < count; i++) {
        Node* child = scanner->right;
        scanner->right = child->right;
        scanner = scanner->right;
        child->right = scanner->left;
        scanner->left = child;
    }
}

// Second part: Vine to Balanced Tree
void vineToTree(Node* root, int nodeCount) {
    // Calculate number of leaves in the bottom level
    int leaves = nodeCount + 1 - (1 << (int)(log2(nodeCount + 1)));

    // Perform compression for the initial leaves
    compression(root, leaves);
    nodeCount = nodeCount - leaves;

    // Perform compression for the remaining nodes
    while (nodeCount > 1) {
        compression(root, nodeCount / 2);
        nodeCount = nodeCount / 2;
    }
}



// Main DSW algorithm function
void DSW(Node** rootPtr) {
    if (*rootPtr == NULL) return;

    // Create a pseudo-root
    Node pseudoRoot;
    pseudoRoot.right = *rootPtr;
    pseudoRoot.left = NULL;

    // Step 1: Convert BST to a vine (right-skewed tree)
    int nodeCount = treeToVine(&pseudoRoot);

    // Step 2: Convert vine to a balanced tree
    vineToTree(&pseudoRoot, nodeCount);

    // Update the original root
    *rootPtr = pseudoRoot.right;
}

// Function to print inorder traversal of BST
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to find the height of the BST
int height(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

// Function to free the BST
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the DSW algorithm
int main() {
    Node* root = NULL;

    // Create an unbalanced BST
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    insertNode(root, 15);
    insertNode(root, 10);
    insertNode(root, 5);

    printf("Inorder traversal before balancing: ");
    inorderTraversal(root);
    printf("\n");

    printf("Height before balancing: %d\n", height(root));

    // Apply DSW algorithm
    DSW(&root);

    printf("Inorder traversal after balancing: ");
    inorderTraversal(root);
    printf("\n");

    printf("Height after balancing: %d\n", height(root));

    // Free the memory
    freeTree(root);

    return 0;
}

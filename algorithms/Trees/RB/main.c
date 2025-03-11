#include <stdio.h>
#include <stdlib.h>

// Colors
#define RED 0
#define BLACK 1

// Node structure
typedef struct Node {
    int data;
    int color; // 0 for RED, 1 for BLACK
    struct Node *left, *right, *parent;
} Node;

// Red-Black Tree structure
typedef struct RBTree {
    Node *root;
    Node *NIL; // For representing NULL leaves
} RBTree;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED; // New nodes are always red
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

// Initialize an empty Red-Black Tree
RBTree* initializeRBTree() {
    RBTree* tree = (RBTree*)malloc(sizeof(RBTree));

    // Create a sentinel NIL node (black)
    Node* nilNode = (Node*)malloc(sizeof(Node));
    nilNode->color = BLACK;
    nilNode->left = NULL;
    nilNode->right = NULL;
    nilNode->parent = NULL;

    tree->NIL = nilNode;
    tree->root = tree->NIL;

    return tree;
}

// Left Rotation
void leftRotate(RBTree* tree, Node* x) {
    // Store y (right child of x)
    Node* y = x->right;

    // Turn y's left subtree into x's right subtree
    x->right = y->left;
    if (y->left != tree->NIL) {
        y->left->parent = x;
    }

    // Link x's parent to y
    y->parent = x->parent;

    // Handle root case
    if (x->parent == tree->NIL) {
        tree->root = y;
    }
    // Handle x as left child case
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    // Handle x as right child case
    else {
        x->parent->right = y;
    }

    // Put x on y's left
    y->left = x;
    x->parent = y;
}

// Right Rotation
void rightRotate(RBTree* tree, Node* y) {
    // Store x (left child of y)
    Node* x = y->left;

    // Turn x's right subtree into y's left subtree
    y->left = x->right;
    if (x->right != tree->NIL) {
        x->right->parent = y;
    }

    // Link y's parent to x
    x->parent = y->parent;

    // Handle root case
    if (y->parent == tree->NIL) {
        tree->root = x;
    }
    // Handle y as left child case
    else if (y == y->parent->left) {
        y->parent->left = x;
    }
    // Handle y as right child case
    else {
        y->parent->right = x;
    }

    // Put y on x's right
    x->right = y;
    y->parent = x;
}

// Fix violations after insertion
void insertFixup(RBTree* tree, Node* z) {
    // Continue until we reach the root or no red-red conflict
    while (z->parent != tree->NIL && z->parent->color == RED) {
        // Parent is LEFT child of grandparent
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right; // Uncle

            // Case 1: Uncle is RED - Recolor
            if (y != tree->NIL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent; // Move up to grandparent
            }
            else {
                // Case 2: Uncle is BLACK, z is RIGHT child - Left Rotation
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(tree, z);
                }

                // Case 3: Uncle is BLACK, z is LEFT child - Right Rotation
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(tree, z->parent->parent);
            }
        }
        // Parent is RIGHT child of grandparent (mirror cases)
        else {
            Node* y = z->parent->parent->left; // Uncle

            // Case 1: Uncle is RED - Recolor
            if (y != tree->NIL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent; // Move up to grandparent
            }
            else {
                // Case 2: Uncle is BLACK, z is LEFT child - Right Rotation
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(tree, z);
                }

                // Case 3: Uncle is BLACK, z is RIGHT child - Left Rotation
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(tree, z->parent->parent);
            }
        }
    }

    // Ensure root is always black
    tree->root->color = BLACK;
}

// Insert a new node
void insert(RBTree* tree, int data) {
    // Create a new node
    Node* z = createNode(data);
    z->left = tree->NIL;
    z->right = tree->NIL;

    // Find position using standard BST insertion
    Node* y = tree->NIL; // trailing pointer
    Node* x = tree->root; // current pointer

    while (x != tree->NIL) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    // Set parent
    z->parent = y;

    // Insert z properly
    if (y == tree->NIL) {
        tree->root = z; // Tree was empty
    }
    else if (z->data < y->data) {
        y->left = z;
    }
    else {
        y->right = z;
    }

    // Fix Red-Black properties
    insertFixup(tree, z);
}

// Search for a key
Node* search(RBTree* tree, int key) {
    Node* current = tree->root;

    while (current != tree->NIL && key != current->data) {
        if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return current;
}

// Find the minimum node in a subtree
Node* minimum(RBTree* tree, Node* x) {
    while (x->left != tree->NIL) {
        x = x->left;
    }
    return x;
}

// Replace one subtree with another
void transplant(RBTree* tree, Node* u, Node* v) {
    if (u->parent == tree->NIL) {
        tree->root = v;
    }
    else if (u == u->parent->left) {
        u->parent->left = v;
    }
    else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

// Fix the tree after deletion
void deleteFixup(RBTree* tree, Node* x) {
    while (x != tree->root && x->color == BLACK) {
        if (x == x->parent->left) {
            Node* w = x->parent->right; // Sibling

            // Case 1: Sibling is red
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(tree, x->parent);
                w = x->parent->right;
            }

            // Case 2: Sibling's children are both black
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            }
            else {
                // Case 3: Sibling's right child is black
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(tree, w);
                    w = x->parent->right;
                }

                // Case 4: Sibling's right child is red
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(tree, x->parent);
                x = tree->root; // Terminate the loop
            }
        }
        else { // Mirror cases when x is a right child
            Node* w = x->parent->left; // Sibling

            // Case 1: Sibling is red
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(tree, x->parent);
                w = x->parent->left;
            }

            // Case 2: Sibling's children are both black
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            }
            else {
                // Case 3: Sibling's left child is black
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(tree, w);
                    w = x->parent->left;
                }

                // Case 4: Sibling's left child is red
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(tree, x->parent);
                x = tree->root; // Terminate the loop
            }
        }
    }

    x->color = BLACK; // Ensure property 2 (root is black)
}

// Delete a node
void delete(RBTree* tree, Node* z) {
    Node* y = z;
    Node* x;
    int yOriginalColor = y->color;

    // Case 1: No left child
    if (z->left == tree->NIL) {
        x = z->right;
        transplant(tree, z, z->right);
    }
    // Case 2: No right child
    else if (z->right == tree->NIL) {
        x = z->left;
        transplant(tree, z, z->left);
    }
    // Case 3: Both children exist
    else {
        // Find successor (minimum in right subtree)
        y = minimum(tree, z->right);
        yOriginalColor = y->color;
        x = y->right;

        // Case 3a: Successor is direct child of z
        if (y->parent == z) {
            x->parent = y;
        }
        // Case 3b: Successor is deeper
        else {
            transplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        // Replace z with y
        transplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    // If original color was BLACK, fix violations
    if (yOriginalColor == BLACK) {
        deleteFixup(tree, x);
    }

    free(z); // Free memory
}

// Delete a node by key
void deleteByKey(RBTree* tree, int key) {
    Node* z = search(tree, key);
    if (z != tree->NIL) {
        delete(tree, z);
    }
    else {
        printf("Key %d not found in the tree\n", key);
    }
}

// In-order traversal
void inorderTraversal(RBTree* tree, Node* root) {
    if (root != tree->NIL) {
        inorderTraversal(tree, root->left);
        printf("%d(%s) ", root->data, root->color == RED ? "R" : "B");
        inorderTraversal(tree, root->right);
    }
}

// Display the tree
void display(RBTree* tree) {
    if (tree->root == tree->NIL) {
        printf("Empty tree\n");
        return;
    }

    printf("Inorder traversal: ");
    inorderTraversal(tree, tree->root);
    printf("\n");
}

// Main function for testing
int main() {
    RBTree* tree = initializeRBTree();

    // Insert some values
    insert(tree, 10);
    insert(tree, 20);
    insert(tree, 30);
    insert(tree, 15);
    insert(tree, 5);

    printf("After insertion:\n");
    display(tree);

    // Search for a value
    Node* result = search(tree, 15);
    if (result != tree->NIL) {
        printf("Found: %d\n", result->data);
    } else {
        printf("Not found\n");
    }

    // Delete nodes
    printf("\nDeleting 20:\n");
    deleteByKey(tree, 20);
    display(tree);

    printf("Deleting 10:\n");
    deleteByKey(tree, 10);
    display(tree);

    return 0;
}

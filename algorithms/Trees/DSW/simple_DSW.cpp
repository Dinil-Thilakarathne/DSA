#include <iostream>
#include <cmath>

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
    private:
        Node* root;
        Node* insert(Node* root, int data);
        void inorder(Node* root);
        void preorder(Node* root);
        void postorder(Node* root);
        Node* search(Node* root, int data);
        Node* remove(Node* root, int data);
        Node* findMin(Node* root);
        int countNodes(Node* root);
        int height(Node* root);
    public:
        BST();
        Node* getRoot() { return root; }
        void setRoot(Node* root) { this->root = root; }
        void insert(int data);
        void inorder();
        void preorder();
        void postorder();
        Node* search(int data);
        void remove(int data);
        int countNodes() { return countNodes(root); }
        int height() { return height(root); }
};

// Constructor
BST::BST()
{
    root = NULL;
}

Node* BST::insert(Node* root, int data)
{
    if (root == NULL)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void BST::insert(int data)
{
    root = insert(root, data);
}

void BST::inorder(Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

void BST::inorder()
{
    inorder(root);
    std::cout << std::endl;
}

void BST::preorder(Node* root)
{
    if (root == NULL)
        return;
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void BST::preorder()
{
    preorder(root);
    std::cout << std::endl;
}

void BST::postorder(Node* root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

void BST::postorder()
{
    postorder(root);
    std::cout << std::endl;
}

Node* BST::search(Node* root, int data)
{
    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}

Node* BST::search(int data)
{
    return search(root, data);
}

Node* BST::remove(Node* root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = remove(root->left, data);
    else if (data > root->data)
        root->right = remove(root->right, data);
    else 
    {
        if (root->left == NULL) 
        {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) 
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }
    return root;
}

void BST::remove(int data)
{
    root = remove(root, data);
}

Node* BST::findMin(Node* root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

int BST::countNodes(Node* root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int BST::height(Node* root)
{
    if (root == NULL)
        return 0;
    return 1 + std::max(height(root->left), height(root->right));
}


// printTree function for visualizing the tree

void printTree_(Node* root, const std::string& prefix, bool isLeft)
{
    if (root != nullptr)
    {
        std::cout << prefix;

        std::cout << (isLeft ?  "├─l─ " : "└─r─ ");

        std::cout << root->data << std::endl;

        printTree_(root->left, prefix + (isLeft ? "│   " : "    "), true);
        printTree_(root->right, prefix + (isLeft ? "│   " : "    "), false);
    }
}

void printTree(BST& bst)
{
    Node* root = bst.getRoot();
    printTree_(root, "", false);
}

void printTree(Node* root)
{
    printTree_(root, "", false);
}


// rotateRight and rotateLeft functions for DSW algorithm

Node* rotateRight(Node* root)
{
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

Node* rotateLeft(Node* root)
{
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}


// DSW Algorithm

Node* makeVine(Node* root)
{
    Node* grand = nullptr;
    Node* parent = root;
    
    while (parent != nullptr)
    {
        if (parent->left != nullptr)
        {
            parent = rotateRight(parent);
            if (grand)
                grand->right = parent;
            else
                root = parent;
        }
        else
        {
            grand = parent;
            parent = parent->right;
        }
    }
    return root;
}

Node* compress(Node* root, int count)
{
    Node* grand = nullptr;
    Node* parent = root;
    for (int i = 0; i < count; i++)
    {
        parent = rotateLeft(parent);

        if (i == 0) root = parent; // update root
        if (grand) grand->right = parent; // update previous grand's right child

        grand = parent; // update new grand
        parent = parent->right;
    }
    return root;
}

void balance(BST& bst)
{
    int size = bst.countNodes();
    Node* root = bst.getRoot();

    if (root == nullptr)
        return;

    if (bst.height() < size)
        root = makeVine(root);

    // printTree(root);

    // Don't think alot about this goofy ahh calculation, it just finds the perfect size for the tree
    int perfectSize = pow(2, (int)log2(size + 1)) - 1;

    root = compress(root, size - perfectSize);

    for (int m = perfectSize / 2; m > 0; m /= 2)
        root = compress(root, m);

    bst.setRoot(root);
}


int main()
{
    BST bst;
    int arr[] = {70, 30, 85, 20, 40, 60, 50, 10, 25, 35, 45, 55, 65, 75, 80, 5, 15, 33, 43, 53, 63, 73, 83, 90, 95};

    for (int i : arr)
        bst.insert(i);

    printTree(bst);
    std::cout << "Height: " << bst.height() << std::endl;
    std::cout << "Node count: " << bst.countNodes() << std::endl;
        
    // prefer to use DSW algorithm for balancing
    balance(bst);

    std::cout << "After balancing:" << std::endl;

    printTree(bst);
    std::cout << "Height: " << bst.height() << std::endl;
    std::cout << "Node count: " << bst.countNodes() << std::endl;
}

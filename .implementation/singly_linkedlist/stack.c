#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Push operation to add an element to the stack
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d to the stack\n", data);
}

// Pop operation to remove an element from the stack
int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow! Unable to pop\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    printf("Popped %d from the stack\n", poppedData);
    return poppedData;
}

// Peek operation to view the top element of the stack
int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Helper function to print the current stack
void printStack(struct Node* top) {
    printf("Stack elements: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate stack operations
int main() {
    struct Node* stack = NULL; // Initialize the stack as empty

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printStack(stack);

    printf("Top element is %d\n", peek(stack));

    pop(&stack);
    printStack(stack);

    printf("Top element is %d\n", peek(stack));

    return 0;
}

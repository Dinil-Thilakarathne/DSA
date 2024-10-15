#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Define the structure for the queue with pointers to the front and rear nodes
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Enqueue operation to add an element to the rear of the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        // If the queue is empty, both front and rear are the new node
        queue->front = queue->rear = newNode;
        printf("Enqueued %d to the queue\n", data);
        return;
    }
    // Otherwise, add the new node to the end of the queue and update rear
    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("Enqueued %d to the queue\n", data);
}

// Dequeue operation to remove an element from the front of the queue
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue underflow! Unable to dequeue\n");
        return -1;
    }
    // Store the previous front and move front one node ahead
    struct Node* temp = queue->front;
    int dequeuedData = temp->data;
    queue->front = queue->front->next;

    // If the queue is now empty, set rear to NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    printf("Dequeued %d from the queue\n", dequeuedData);
    return dequeuedData;
}

// Peek operation to view the front element of the queue
int peek(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

// Helper function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Helper function to print the current queue
void printQueue(struct Queue* queue) {
    struct Node* temp = queue->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate queue operations
int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printQueue(queue);

    printf("Front element is %d\n", peek(queue));

    dequeue(queue);
    printQueue(queue);

    printf("Front element is %d\n", peek(queue));

    return 0;
}

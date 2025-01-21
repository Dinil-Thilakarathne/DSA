#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = *head_ref;

    if (*head_ref != NULL) {
        while (last->next != *head_ref) {
            last = last->next;
        }
        last->next = new_node;
    } else {
        new_node->next = new_node; // For the first node
    }

    *head_ref = new_node;
}

// Function to delete a node from a circular linked list
void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL) return;

    struct Node *curr = *head_ref, *prev;

    // Check if the node to be deleted is the head node
    if (curr->data == key && curr->next == *head_ref) {
        *head_ref = NULL;
        free(curr);
        return;
    }

    // If the head needs to be deleted and there are multiple nodes
    if (curr->data == key) {
        while (curr->next != *head_ref) curr = curr->next;
        curr->next = (*head_ref)->next;
        free(*head_ref);
        *head_ref = curr->next;
        return;
    }

    // Traverse the list to find the node to be deleted
    while (curr->next != *head_ref && curr->next->data != key) {
        curr = curr->next;
    }

    if (curr->next->data == key) {
        struct Node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }
}


// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = *head_ref;

    if (*head_ref != NULL) {
        while (last->next != *head_ref) {
            last = last->next;
        }
        last->next = new_node;
    } else {
        *head_ref = new_node;
        new_node->next = new_node; // First node
    }
}

// Function to print nodes in a circular linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("Circular Linked List after insertion at end: ");
    displayList(head);

    insertAtBeginning(&head, 5);
    printf("Circular Linked List after insertion at beginning: ");
    displayList(head);

    return 0;
}

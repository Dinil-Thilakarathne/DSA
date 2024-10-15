#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int newData)
{
    // allocate memory for the new Node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    // assign data to the new Node
    newNode->data = newData;

    // make the new Node's next point to the current head
    newNode->next = *head;

    // move the head to point to the new Node
    *head = newNode;
}

void reverse(struct Node** head)
{
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while(current != NULL)
    {
        next = current->next; // store the next Node
        current->next = prev; // reverse the link
        prev = current; // move the previous pointer to the current Node
        current = next; // move to the next Node
    }
    // finally change the head pointer to point to the reversed list
    *head = prev;
}

void printList(struct Node* head)
{
    struct Node* temp = head; // temporary pointer to traverse the list
    while (temp!= NULL)
    {
        printf("%d ", temp->data); // print the data of the current Node
        temp = temp->next; // move to the next Node
    }
}
int main()
{
    // create an empty linked list
    struct Node* head = NULL;

    // insert elements at the beginning of the list
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printList(head);

    // reverse the linked list
    reverse(&head);

    printf("\nReversed Linked List: ");
    printList(head);
    puts("");
}

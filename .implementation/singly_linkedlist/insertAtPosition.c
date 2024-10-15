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

void insertAtPosition(struct Node** head, int newData, int position)
{
    // if the list is empty follows the insertAtHead method and insert new node as  head
    if(*head == NULL)
    {
        insertAtBeginning(head, newData);
        return;
    }

    // create a temporary pointer to traverse the list
    struct Node* temp = *head;
    for(int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    // if the position is beyond the end of the list
    if(temp == NULL)
    {
        printf("Position is out of bounds \n");
        return;
    }

    // allocate memory for the new Node (only allocate memory if necessary)
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    // assign data to the new Node
    newNode->data = newData;

    // make the new Node's next point to the Node at the specified position
    newNode->next = temp->next;

    // update the next pointer of the Node before the specified position
    temp->next = newNode;

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
    insertAtBeginning(&head, 8);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 6);

    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    insertAtPosition(&head,	5, 10);

    printList(head);
}

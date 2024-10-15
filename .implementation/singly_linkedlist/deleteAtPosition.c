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

void deleteAtPosition(struct Node** head, int position)
{
    // if the list is empty nothing to delete
    if(*head == NULL)
    {
        printf("List is empty \n");
        return;
    }

    // if the position is 0, delete the first Node
    if(position == 0)
    {
        struct Node* temp = *head;
        *head = (*head)->next; // change the head
        free(temp); // free the memory occupied by the first Node
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

    // set the prev node next pointer to the next node of the target node
    struct Node* nextNode = temp->next->next;

    // free the memory occupied by the target node
    free(temp->next);

    // set the temp node next pointer to the next node of the target node
    temp->next = nextNode;

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
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    deleteAtPosition(&head,	0);

    printList(head);
}

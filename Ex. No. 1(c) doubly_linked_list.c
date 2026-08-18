//Ex. No. 1(c) Doubly Linked List Operations

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertBegin()
{
    int data;
    printf("\n Enter node data: ");
	scanf("%d",&data);
    Node* newNode = createNode(data);
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
     printf("\n Node inserted at the beginning.\n");
}

void insertEnd()
{
    int data;
    printf("\n Enter node data: ");
	scanf("%d",&data);
    Node* newNode = createNode(data);
    if (tail == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("\n Node inserted at the end.\n");
}

void deleteBegin()
{
    if (head == NULL)
    {
        printf("\n List is empty.\n");
        return;
    }
    Node* temp = head;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
    printf("\n Node deleted from start.\n");
}

void deleteEnd()
{
    if (tail == NULL)
    {
        printf("\n List is empty.\n");
        return;
    }
    Node* temp = tail;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
    printf("\n Node deleted from end.\n");
}

void print()
{
    Node* temp = head;
    printf("\n Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    int choice;
	while(1)
	{
	    printf("\n\n ---------------- Doubly Linked List Operations ------------------");
	    printf("\n 1. Insert first 2. insert end 3. delete first 4. delete end 5. Exit \n");
		printf("\n Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insertBegin();  print(); break;
			case 2: insertEnd();    print(); break;
			case 3: deleteBegin();  print(); break;
			case 4: deleteEnd();    print(); break;
			case 5: exit(0);
			default:printf("\n Wrong Choice");
		}
	}

}

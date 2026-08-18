// Ex.No. 1(d) Circular Singly Linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
struct node *head;

void beg_insert()
{
 struct node *ptr,*temp;
 int item;
 ptr = (struct node *)malloc(sizeof(struct node));
 if(ptr == NULL) printf("\n OVERFLOW");
 else
 {
 printf("\n Enter the node data?: ");
 scanf("%d",&item);
 ptr -> data = item;
 if(head == NULL)
 {
 head = ptr;
 ptr -> next = head;
 }
 else
 {
    temp = head;
    while(temp->next != head)
    temp = temp->next;
    ptr->next = head;
    temp -> next = ptr;
    head = ptr;
 }
 printf("\n node inserted \n");
 }
}

void last_insert()
{
 struct node *ptr,*temp;
 int item;
 ptr = (struct node *)malloc(sizeof(struct node));
 if(ptr == NULL) printf("\n OVERFLOW\n");
 else
 {
 printf("\n Enter Data?: ");
 scanf("%d",&item);
 ptr->data = item;
 if(head == NULL)
 {
 head = ptr;
 ptr -> next = head;
 }
 else
 {
 temp = head;
 while(temp -> next != head)
 {
 temp = temp -> next;
 }
 temp -> next = ptr;
 ptr -> next = head;
 }
 printf("\n node inserted \n");
 }
}

void begin_delete()
{
 struct node *ptr;
 if(head == NULL) printf("\nUNDERFLOW");
 else if(head->next == head)
 {
 head = NULL;
 free(head);
 printf("\n node deleted\n");
 }
 else
 {
    ptr = head;
    while(ptr -> next != head)
    ptr = ptr -> next;
    ptr->next = head->next;
    free(head);
    head = ptr->next;
    printf("\n node deleted \n");
 }
}
void last_delete()
{
 struct node *ptr, *preptr;
 if(head==NULL) printf("\nUNDERFLOW");
 else if (head->next == head)
 {
 head = NULL;
 free(head);
 printf("\n node deleted \n");
 }
 else
 {
 ptr = head;
 while(ptr->next != head)
 {
 preptr=ptr;
 ptr = ptr->next;
 }
 preptr->next = ptr -> next;
 free(ptr);
 printf("\n node deleted\n");
 }
}

void display()
{
 struct node *ptr;
 ptr=head;
 if(head == NULL) printf("\n nothing to print \n");
 else
 {
 printf("Head ");
 while(ptr -> next != head)
 {
 printf("--> %d", ptr -> data);
 ptr = ptr -> next;
 }
 printf("--> %d", ptr -> data);
 }
}

void main ()
{
 int choice;
 while(1)
 {
 printf("\n\n ----------- Circular Singly Linked List ------------");
 printf("\n 1. Insert at beginning   2. Insert at last 3. Delete from Beginning 4. Delete from last 5. Exit");
 printf("\n Enter your choice?: ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1: beg_insert(); display(); break;
 case 2: last_insert(); display(); break;
 case 3: begin_delete(); display(); break;
 case 4: last_delete(); display(); break;
 case 5: exit(0);
 default: printf("\n Please enter valid choice..");
 }
 }
}

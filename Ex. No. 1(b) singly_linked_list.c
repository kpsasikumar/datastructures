//Ex.No. 1(b) Singly Linked List Operations

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
   struct node *ptr;
   int item;
   ptr = (struct node *) malloc(sizeof(struct node *));
   if(ptr == NULL)
   {
     printf("\n OVERFLOW \n");
   }
   else
   {
       printf("\n Enter value: ");
       scanf("%d",&item);
       ptr->data = item;
       ptr->next = head;
       head = ptr;
       printf("\n Node inserted \n");
 }
}

void last_insert()
{
   struct node *ptr,*temp;
   int item;
   ptr = (struct node*)malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\n OVERFLOW");
   }
    else
   {
       printf("\n Enter value: ");
       scanf("%d",&item);
       ptr->data = item;
       if(head == NULL)
       {
           ptr -> next = NULL;
           head = ptr;
           printf("\n Node inserted \n");
       }
       else
       {
           temp = head;
           while (temp -> next != NULL)
           {
               temp = temp -> next;
           }
           temp->next = ptr;
           ptr->next = NULL;
           printf("\n Node inserted");
       }
    }
}

void begin_delete()
{
 struct node *ptr;
 if(head == NULL)
 {
   printf("\n List is empty \n");
 }
 else
 {
     ptr = head;
     head = ptr->next;
     free(ptr);
     printf("\n Node deleted from the beginning ...\n");
 }
}

void last_delete()
{
 struct node *ptr,*ptr1;
 if(head == NULL)
 {
     printf("\n list is empty");
 }
 else if(head -> next == NULL)
 {
     head = NULL;
     free(head);
     printf("\n Only node of the list deleted ...\n");
 }
 else
 {
 ptr = head;
 while(ptr->next != NULL)
 {
     ptr1 = ptr;
     ptr = ptr ->next;
 }
     ptr1->next = NULL;
     free(ptr);
     printf("\n Deleted Node from the last ...\n");
 }
}

void display()
{
 struct node *ptr;
 ptr = head;
 if(ptr == NULL)
 {
 printf("\n Nothing to print");
 }
 else
 {
 printf("\n Head ");
 while (ptr!=NULL)
 {
 printf("--> %d",ptr->data);
 ptr = ptr -> next;
 }
 }
}

void main()
{
 int ch;
 while(1)
 {
 printf("\n\n ----------------- Singly Linked List Operations ----------------");
 printf("\n 1. Insert at Begin  2. Insert at Last  3. Delete Begin  4. Delete Last  5. Exit ");
 printf("\n Enter your choice: ");
 scanf("%d",&ch);
 switch(ch)
 {
   case 1: beg_insert(); display();break;
   case 2: last_insert(); display();break;
   case 3: begin_delete(); display();break;
   case 4: last_delete(); display();break;
   case 5: exit(0);
   default: printf("\n Enter valid choice..");
 }
 }
}

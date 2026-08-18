//Ex. No. 2(d) Priority Queue

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct pqueue
{
  int data, prior;
} p[MAX], temp;

int front = -1, rear = -1;

void display()
{
	if(rear == -1)
	{
		printf(" Queue is empty \n");
		return;
	}
	printf("\n Priority Queue \t Element \t Priority ");
	for(int i = front; i <= rear; i++)
    printf("\n\t\t\t  %d \t\t %d ", p[i].data, p[i].prior);
}

void enqueue()
{
	if(rear == MAX-1) printf("\n Queue is Full \n");
	else if(rear == -1)
	{
		front = rear = 0;
		printf("\nEnter the element and priority\n");
		scanf("%d %d", &p[rear].data, &p[rear].prior);
	}
	else
	{
		rear++;
		printf("\n Enter the element and priority \n");
		scanf("%d %d", &p[rear].data, &p[rear].prior);
		for(int i = rear; i > front; i--)
		{
			if(p[i].prior > p[i-1].prior)
			{
				temp=p[i-1];
				p[i-1]=p[i];
				p[i]=temp;
			}
		}
	}
}

void dequeue()
{
	if(front == -1) printf("\n Queue is Empty \n");
	else if(front == rear)
	{
		front = rear = -1;
	}
	else
	{
		printf("\n Element %d with priority %d is deleted \n", p[front].data, p[front].prior);
		front++;
	}
}

void main()
{
	int ch;
	while(1)
	{
		printf("\n\n ------------ Priority Queue -------------");
		printf("\n MENU: 1. Insert \t 2. Delete \t 3. Exit \n");
		printf("\n Enter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	enqueue(); display(); break;
			case 2:	dequeue(); display(); 	break;
			case 3:	exit(0);
			default:printf("Invalid choice\n");
		}
	}
}

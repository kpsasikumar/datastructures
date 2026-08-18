// Ex. No. 2(c) Circular Queue using Arrays

#include <stdio.h>
#include<stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull()
{
  if ((front == (rear + 1) % SIZE) || (front == 0 && rear == SIZE - 1)) return 1;
  else return 0;
}

int isEmpty()
{
  if (front == -1) return 1;
  else return 0;
}

void enqueue(int element)
{
  if (isFull()) printf("\n Queue is Full \n");
  else
  {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = element;
    printf("\n  %d is inserted into Queue \n", element);
  }
}

void dequeue()
{
  int element;
  if (isEmpty()) printf("\n Queue is Empty \n");
  else
  {
        element = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else front = (front + 1) % SIZE;
        printf("\n %d is deleted from Queue \n", element);
  }
}

void display()
{
  int i;
  if (isEmpty()) printf(" \n Empty Queue \n");
  else
  {
    printf("\n Front: %d \t Rear: %d \n ", front, rear);
    printf("\n Queue Items are.....");
    for (i = front; i != rear; i = (i + 1) % SIZE)
    {
      printf("%d ", queue[i]);
    }
      printf("%d ", queue[i]);
  }
}

void main()
{
	int n, ch;
	printf("\n ------------ Circular Queue ---------------");
	while(1)
	{
		printf("\n MENU: 1.Insert \t 2. Delete \t 3.Quit");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: printf("\n Enter the element:"); scanf("%d",&n); enqueue(n); display(); break;
		case 2: dequeue(); display(); break;
		case 3: exit(0); break;
		default:printf("\n Invalid Choice \n");
		}
	}
}



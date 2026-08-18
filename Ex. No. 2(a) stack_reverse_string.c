//Ex.No. 2(a) String Reverse Operation using Stack

#include <stdio.h>
#include <string.h>

int top, stack[20];

void push(char x)
{
    stack[++top]=x;
}

void pop()
{
    printf("%c",stack[top--]);
}

void main()
{
   int i, n;
   char str[20];
   printf("\n Enter the String: ");
   scanf("%s", str);
   n = strlen(str);
   for(i=0;i<n;i++)  push(str[i]);
   printf("\n Reverse String :" );
   for(i=0;i<n;i++)  pop();
}

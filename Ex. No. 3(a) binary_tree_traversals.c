// Ex.No. 3(a) BINARY TREE TRAVERSALS (IN-ORDER, PRE-ORDER AND POST-ORDER)
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL, *rptr, *lptr;

void createTree(struct node *ptr, int item)
{
    char option;
    int newItem;

    if (ptr == NULL)
    {
        ptr = malloc(sizeof(struct node));
        ptr->left = ptr->right = NULL;
        root = ptr;
    }
    ptr->data = item;

    printf("\n Does the node %d have left subtree? [y/n]: ", item);
    scanf(" %c", &option);
    if (option == 'Y' || option == 'y')
    {
        lptr = malloc(sizeof(struct node));
        ptr->left = lptr;
        printf("\n Enter the item to be inserted: ");
        scanf("%d", &newItem);
        createTree(lptr, newItem);
    }
    else  ptr->left = NULL;

    printf("\n Does the node %d have right subtree? [y/n]: ", item);
    scanf(" %c", &option);
    if (option == 'Y' || option == 'y')
    {
        rptr = malloc(sizeof(struct node));
        ptr->right = rptr;
        printf("\n Enter the item to be inserted: ");
        scanf("%d", &newItem);
        createTree(rptr, newItem);
    }
    else ptr->right = NULL;

}

void inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

void preorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void display(struct node *ptr)
{
    if (ptr == NULL) printf("\n Binary Tree is empty");
    else
    {
        printf("\n In-order traversal   : "); inorder(ptr);
        printf("\n Pre-order traversal  : "); preorder(ptr);
        printf("\n Post-order traversal : "); postorder(ptr);
    }
    printf("\n");
}

void main()
{
    int choice, item;
    while (1)
    {
        printf("\n Binary Tree Traversals \n -----------------------");
        printf("\n 1. Create Binary Tree \n 2. Binary Tree Traversals \n 3. Exit\n");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:  printf("\n Enter the root node : ");
                     scanf("%d", &item);
                     createTree(root, item); break;
            case 2:  display(root);break;
            case 3:  exit(0);
            default: printf("\n Invalid choice \n");
        }
    }
}

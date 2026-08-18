// Ex. No. 3(b) AVL TREE ROTATIONS

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int key, height;
  struct Node *right, *left;
}Node;

int height(Node *T)
{
  if (T == NULL)  return 0;
  return T->height;
}

int max(int a, int b)
{
  return (a > b) ? a : b;
}

Node *newNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

Node *rightRotate(Node *y)
{
  Node *x = y->left;
  Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

Node *leftRotate(Node *x)
{
  Node *y = x->right;
  Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

int getBalance(Node *T)
{
  if (T == NULL) return 0;
  return height(T->left) - height(T->right);
}

Node *insert(Node *node, int key)
{
    if (node == NULL)  return (newNode(key));

    if (key < node->key)  node->left = insert(node->left, key);

    else if (key > node->key)   node->right = insert(node->right, key);

    else return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)   return rightRotate(node);

    if (balance < -1 && key > node->right->key) return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void printPreOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void main()
{
  Node *root = NULL;
  root = insert(root, 35);
  root = insert(root, 45);
  root = insert(root, 65);
  root = insert(root, 55);
  root = insert(root, 75);
  root = insert(root, 15);
  root = insert(root, 25);
  printPreOrder(root);
}

/*
OUTPUT:     45 25 15 35 65 55 75

                    45
                   /  \
                 25    65
                / \   /  \
              15  35 55   75
*/

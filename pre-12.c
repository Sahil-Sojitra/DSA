
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter the data(-1 for no node): ");
    scanf("%d", &x);

    if (x == -1)
    {
        return NULL; // Use NULL instead of 0
    }

    newnode->data = x;

    printf("Enter the left child of %d: ", x);
    newnode->left = create();

    printf("Enter the right child of %d: ", x);
    newnode->right = create();

    return newnode;
}

void display(struct node *root)
{
    if (root == NULL)
    {
        return; 
    }

    display(root->left);    
    printf("%d ", root->data); 
    display(root->right);      
}

int main()
{
    struct node *root;
    root = create();
    display(root);
    return 0;
}

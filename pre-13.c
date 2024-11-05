
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
        return NULL; 
    }

    newnode->data = x;

    printf("Enter the left child of %d: ", x);
    newnode->left = create();

    printf("Enter the right child of %d: ", x);
    newnode->right = create();

    return newnode;
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node * root){  
    if(root == NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root){
    if (root==NULL)
    {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
    
}
int main()
{
    struct node *root;
    root = create();
    printf("the tree in inorder traversal : ");
    inorder(root);
    printf("\n");
    printf("the tree in preorder traversal : ");
    preorder(root);
    printf("\n");
    printf("the tree in postorder traversal : ");
    postorder(root);
    return 0;
}

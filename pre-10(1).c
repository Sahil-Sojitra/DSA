#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node *L = NULL;
struct node *R = NULL;

struct node *create_new_node(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = value;
    newnode->lptr = NULL;
    newnode->rptr = NULL;
    return newnode;
}

void insert(struct node *M, int value)
{
    struct node *newnode = create_new_node(value);

    if (R == NULL)
    {
        newnode->lptr = NULL;
        newnode->rptr = NULL;
        L = R = newnode;
        return;
    }
    if (M == L)
    {
        newnode->lptr = NULL;
        newnode->rptr = M;
        M->lptr = newnode;
        L = newnode;
        return;
    }

    newnode->lptr = M->lptr;
    newnode->rptr = M;
    M->lptr = newnode;
    (newnode->lptr)->rptr = newnode;
}

void delete(struct node*old){
    if(R==NULL){
        printf("List is empty\n");
    }
    if(L==R){
        L=R=NULL;
    }
    else if(old==L){
        L = L->rptr;
        L->lptr = NULL;
    }
    else{
        (old->lptr)->rptr = old->rptr;
        (old->rptr)->lptr = old->lptr;
    }
    free(old);
}
void display()
{
    struct node *temp = L;
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->rptr;
    }
    printf("\n");
}
int main()
{
    insert(L, 10);
    insert(L, 20);
    insert(L, 30);
    display();
    delete(L);
    display();
    return 0;
}
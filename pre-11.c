#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

int main()
{
    struct node *head, *newnode, *temp;
    head = 0;
    int choice;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data : ");
        scanf("%d", &newnode->info);
        newnode->link = 0;

        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->link = newnode;
            temp = newnode;
        }
        temp->link = head;

        printf("do you want to continue (y,n) :  ");
        scanf("%d", &choice);
    }

    printf("the linked list is : ");
    temp = head;
    while (temp->link != head)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("%d", temp->info);
    return 0;
}
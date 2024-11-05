#include <stdio.h>
#include <math.h>
int main()
{
    struct node
    {
        int info;
        struct node *link;
    };
    struct node *head, *newnode, *temp;
    head = 0;
    int choice;
    while (choice)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
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

        printf("do you want to continue (y,n) :  ");
        scanf("%d", &choice);
    }

    printf("the linked list is : ");
    temp = head;
    while (temp != 0)
    {
        printf("(%d %d)", temp->info,temp->link);
        temp = temp->link;
    }
    return 0;
}
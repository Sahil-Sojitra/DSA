#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node* head, *tail;

void create(){
    head = 0;
    struct node *newnode;
    int choice = 1;
    while(choice){
    newnode= (struct node*)malloc(sizeof(struct node));
    printf("Enter the data in the node : ");
    scanf("%d",&newnode->data);

    newnode->prev=0;
    newnode->next=0;
    
    if(head==0){
        head = tail = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail=newnode;
    }

    printf("Do you want to continue : ");
    scanf("%d",&choice);
    }
}

void insertatbeg(){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data in the node to insert in beg : ");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;

    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insertatend()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data in the node to insert in end : ");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    
    if (head == 0){
        head = tail = newnode;
    }

    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void  insertatpos(){
    struct node *newnode, *temp=head;   
    int pos, i=1;;
    printf("Enter the position for enter at pos : ");
    scanf("%d",&pos);

    if(pos==1){
        insertatbeg();
    }
    else{
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data in the node for insert at the pos : ");
        scanf("%d", &newnode->data);
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev=newnode;
}
}

void insertafterpos()
{
    struct node *newnode, *temp = head;
    int pos, i = 1;
    ;
    printf("Enter the position enter after pos : ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        insertatbeg();
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data in the node to insert after the pos : ");
        scanf("%d", &newnode->data);
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

void delfrombeg(){
    struct node *temp;
    if(head==0){
        printf("List is empty.\n");
    }
    else{
        temp = head;
        head = head->next;
        head->prev=0;
        free(temp);
    }
}

void delfromend(){
    struct node *temp ;
    if(tail==0){
        printf("List is Empty\n");
    }
    else{
        temp=tail;
        tail->prev->next=0;
        tail=tail->prev;
        free(temp);
    }
}

void delfrompos(){
    struct node *temp=head;
    int pos,i=1;
    printf("Enter the position of the node to be deleted : ");
    scanf("%d",&pos); 
    if (pos == 1)
    {
        delfrombeg();
    }
    else{
    while(i<pos){
    temp=temp->next;
    i++;
    } 
    temp->prev->next = temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    }
    }




    void display()
    {
        struct node *temp;
        temp = head;
        while (temp != 0)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }

    int main()
    {
        create();
        display();
        printf("\n");
        insertatbeg();
        display();
        printf("\n");
        insertatbeg();
        display();
        printf("\n");
        insertatend();
        display();
        printf("\n");
        insertatend();
        display();
        printf("\n");
        insertatpos();
        display();
        printf("\n");
        insertatpos();
        display();
        printf("\n");
        insertafterpos();
        display();
        printf("\n");
        delfrombeg();
        printf("the node deleted from the beg : \n");
        display();
        printf("\n");
        delfromend();
        printf("the node is deleted from the end : \n");
        display();
        printf("\n");
        delfrompos();
        display();
        printf("\n");
        return 0;
    }
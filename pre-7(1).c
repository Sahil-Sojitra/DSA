#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *head = NULL;
struct node *avail = NULL;

void push_avail(struct node* node){
    node->link = avail;
    avail = node;
}

struct node* insert(int n){
    if(avail==NULL){
        printf("availability stack underfolw\n");
        return head;
    }
    struct node* newnode=avail;

    avail=avail->link;

    newnode->info = n;
    newnode->link=head;

    head=newnode;
    return newnode;
}

struct node* insend(int n){
    if(avail==NULL){
        printf("availability stack underflow\n");
        return head;
    }
    struct node* newnode = avail;

    avail=avail->link;

    newnode->info=n;
    newnode->link=NULL;

    if(head==NULL){
        head=newnode;
        return newnode;
    }

    struct node *save;
    save = head;

    while(save->link!=NULL){
        save = save->link;
    }
    save->link=newnode;

    return head;
}

struct node* insord(int n){
    if(avail==NULL){
        printf("availability stack underflow\n"); 
        return head;
    }
    struct node* newnode = avail;
    avail=avail->link;

    newnode->info = n;

    if(head==NULL){
        newnode->link = NULL;
        head=newnode;
        return newnode;
    }

    if(newnode->info <= head->info){
        newnode->link = head;
        head = newnode;
        return newnode;
    }

    struct node* save = head;

    while(save->link != NULL && newnode->info >= (save->link)->info){
        save = save->link;
    }

    newnode->link = save->link;
    save->link = newnode;

    return head;
}


void delete(int n){
    if(head==NULL){
        printf("Underflow\n"); 
        return ;
    }
    struct node* save = head;
    struct node* pred;
    while(save->info!= n &&save->link!=NULL){
        pred = save;
        save = save->link;
    }
        if(save->info!=n){
            printf("Not Found\n");
            return;
        }
        if(n==head->info){
            head = head->link;
        }
        else{
            pred->link = save->link;
        }
        free(n);
        printf("Node with value %d deleted\n",n);
}



void avail_stack(int n){
    int i;
    for(i=0; i<n; i++){
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        push_avail(newnode);
    }
}
void print_list()
{
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->info);
        current = current->link;
    }
    printf("NULL\n");
}
int main(){
    avail_stack(100);
    insert(60);
    insert(50);
    insert(40);
    insert(30);
    print_list();
    insert(20);
    insert(10);
    print_list();
    insord(25);
    insord(11);
    insord(35);
    insord(15);
    print_list();
    insord(14);
    insord(55);
    print_list();
    delete(50);
    print_list();
    delete(21);
    print_list();
    return 0;
}

// Linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node  // self referencial structure 
{
    int data;
    struct node *next;
}node;


typedef struct B    // nested structure
{
    node *head;
}B;

node *createnode(int value){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}

void add(B *list, int data)
{
    node *newnode = createnode(data);
    if(list->head==NULL){
        list->head=newnode;
    }
    else{
        node *temp = list->head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void show(B *list){
    node *temp = list->head;
    while (temp!=NULL)
    {
        printf("%d-->%p-->%p\n", temp->data, temp->next, temp);  // 1st %p -> address me kya hai  2nd %p -> address
        temp = temp->next;
    }
    
}

int main(){
    B list;
    list.head=NULL;

    add(&list, 10);
    add(&list, 20);
    add(&list, 30);
    show(&list);
}

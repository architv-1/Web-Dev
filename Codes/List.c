#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

void addfirst(int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

void addlast(int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

int main()
{
    int ch, v, pos;

    do
    {
        printf("1. Insert First \n");
        printf("2. Display Record \n");
        printf("3. Insert At Positin \n");
        printf("Enter Your Choice: ");

        switch (ch)
        {

        case 1:
            printf("Enter the Value: ");
            scanf("%d", &v);
            addfirst(v);
            break;

        case 2:
            printf("Enter the value: ");
            scanf("%d", &v);
            addlast(v);
            break;
        }
    } while (ch != 5);
}
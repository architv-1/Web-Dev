#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *createnode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void addfirst(int value)
{
    struct node *newnode = createnode(value);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }

    printf("Node Insert at First\n");
}

void show()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void addlast(int value)
{
    struct node *newnode = createnode(value);
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
        newnode->prev = temp;
    }
}

void addatposition(int value, int pos)
{
    struct node *newnode = createnode(value);
    int i;
    struct node *temp = head;

    for (i = 0; i < pos; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = newnode;
    }
    newnode->prev = temp;
    temp->next = newnode;
}

void deletefirst()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void deletelast()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

void deleteatposition(int pos)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        int i;
        struct node *temp = head;

        for (i = 0; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("Out of Range\n");
            }
        }
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            head = head->next;
        }
        free(temp);
    }
}


void search(int value)
{
    struct node *temp = head;
    int f = 0;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Record Found\n");
            f = 1;
            break;
        }
        temp = temp->next;
    }
    if (f == 0)
    {
        printf("Record Not Found\n");
    }
}

void count(){
    struct node *temp = head;
    int c=0;
    while(temp!=NULL){
        c++;
        temp = temp->next;
    }
    printf("Total Node in List: %d\n",c);
}

void reverse(){
    struct node *temp = head;
    struct node *ptr = NULL;

    while(temp!=NULL){
        ptr = temp->prev;
        temp->prev = temp->next;
        temp->next = ptr;
        temp = temp->prev;
    }
    if(ptr!=NULL){
        head = ptr->prev;
    }
}
int main()
{
    int ch, v, pos;
    do
    {
        printf("1. Insert First \n");
        printf("2. Display Record \n");
        printf("3. Insert at Last \n");
        printf("4. Insert at any Position \n");
        printf("5. Delete at First \n");
        printf("6. Delete at Last \n");
        printf("7. Delete at any Postion \n");
        printf("8. Search The Value \n");
        printf("9. Count the node \n");
        printf("10. Reverse the node \n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {

        case 1:
            printf("Enter value: ");
            scanf("%d", &v);
            addfirst(v);
            break;

        case 2:
            show();
            break;

        case 3:
            addlast(v);
            break;

        case 4:
            printf("Enter value: ");
            scanf("%d", &v);
            printf("Enter Position: ");
            scanf("%d", &pos);
            addatposition(v, pos);
            break;

        case 5:
            deletefirst();
            break;

        case 6:
            deletelast();
            break;

        case 7:
            printf("Enter Position: ");
            scanf("%d", &pos);
            deleteatposition(pos);
            break;

        case 8:
            printf("Enter value: ");
            scanf("%d", &v);
            search(v);
            break;

            case 9:
            count();
            break;

            case 10:
            reverse();
            break;
        }
    } while (ch != 15);
}
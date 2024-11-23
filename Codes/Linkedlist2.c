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

void show()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        struct node* temp = head;
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

void addAtposition(int value, int pos)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    int i;

    struct node *temp = head;
    for (i = 0; i < pos; i++)
    {
        if (temp == NULL)
        {
            printf("Index Out of Range\n");
        }
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteFirst()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        printf("First Node is Delete\n");
    }
}

void deleteLast()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
    }

    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Only one Node is List\n");
    }
    else
    {
        struct node *temp = head;
        struct node *ptr = NULL;

        while (temp->next != NULL)
        {
            ptr = temp;
            temp = temp->next;
        }

        ptr->next = NULL;
        free(temp);
        printf("Last Node is Delete\n");
    }
}

void deleteAtposition(int pos)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
    }

    else
    {
        struct node *temp = head;
        int i;
        for (i = 0; i < pos; i++)
        {
            if (temp == NULL)
            {
                printf("Index out of Range\n");
                return;
            }
            temp = temp->next;
        }
        struct node *ptr = temp->next;
        if (ptr != NULL)
        {
            temp->next = ptr->next;
            free(ptr);
        }
        printf("Node is Delete after position\n");
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
    if(f==0){
        printf("Record Not Found");
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
int main()
{
    int ch, v, pos;
    do
    {
        printf("1. Insert First \n");
        printf("2. Display Record \n");
        printf("3. Insert Last \n");
        printf("4. Insert At Position \n");
        printf("5. Delete First \n");
        printf("6. Delete Last \n");
        printf("7. Delete At Position \n");
        printf("8. Search Value in List\n");
        printf("9. Number of Node in List\n");
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
            printf("Enter value: ");
            scanf("%d", &v);
            addlast(v);
            break;

        case 4:
            printf("Enter value: ");
            scanf("%d", &v);
            printf("Enter position: ");
            scanf("%d", &pos);
            addAtposition(v, pos);
            break;

        case 5:
            deleteFirst();
            break;

        case 6:
            deleteLast();
            break;

        case 7:
            printf("Enter the Position: ");
            scanf("%d", &pos);
            deleteAtposition(pos);
            show();
            break;

        case 8:
        printf("Enter the Value: ");
            scanf("%d", &v);
            search(v);
            break;

            case 9:
            count();
            show();
            break;
        }
    } while (ch != 10);
}
/*
Linked list
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>   //dynamic memory allocation

struct node
{
    int data;
    struct node *next;
};

typedef struct node snode; 
snode* create_node(int);
void insert_first();
void insert_last();
void insert_pos();
void delete_pos();
void display();
 

snode *newnode, *ptr, *prev, *temp;
snode *first = NULL, *last = NULL;

 int main()
 {
    int choice;
 
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("\n1.Insert node at first");
        printf("\n2.Insert node at last");
        printf("\n3.Insert node at position");
        printf("\n4.Delete Node from any Position");
        printf("\n5.Display ");
        printf("\n6.Exit\n");
        scanf("%d", &choice);
 
        switch (choice)
        {
        case 1: 
            printf("Insert node at first\n");
            insert_first();
            break;
        case 2: 
            printf("Insert node at last\n");
            insert_last();
            break;
        case 3: 
            printf("Insert node at position\n");
            insert_pos();
            break;
        case 4: 
            printf("Delete Node from any Position\n");
            delete_pos();
            break;
        case 5: 
            printf("Display linked List \n");
            display();
            break;
        case 6: 
            exit(0);
        default: 
            printf("\nYou have entered a wrong choice\n");
            break;
        }
   
    }
    return 0;
 }

snode* create_node(int value)  //create a new node
{
    newnode = (snode *)malloc(sizeof(snode));
    if (newnode == NULL)
    {
        printf("\nMemory error");
        return 0;
    }
    else
    {
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }
}
 
void insert_first()   //insert an element at first position
{
    int value;
 
    printf("\nEnter the value for the node:");
    scanf("%d", &value);
    newnode = create_node(value);
    if (first == last && first == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        temp = first;
        first = newnode;
        first->next = temp;
    }
    printf("\nELEMENT IS INSERTED");    
}
 
void insert_last()   //insert an element at last postion
{
    int value;
 
    printf("\nEnter the value for the Node:");    
    scanf("%d", &value);
    newnode = create_node(value);
    if (first == last && last == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        last->next = newnode;
        last = newnode;
        last->next = NULL;
    }
 printf("\n ELEMENT IS INSERTED ");
}    
 
void insert_pos()    //insert an element at any position
{
    int pos, value, cnt = 0, i;
 
    printf("\nEnter the value for the Node:");
    scanf("%d", &value);
    newnode = create_node(value);
     printf("\nEnter the position ");
    scanf("%d", &pos);
    ptr = first;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        cnt++;
    }
    if (pos == 1)
    {
        if (first == last && first == NULL)
        {
            first = last = newnode;
            first->next = NULL;
            last->next = NULL;
        }
        else
        {
            temp = first;
            first = newnode;
            first->next = temp;
        }
        printf("\nELEMENT IS INSERTED");
    }
    else if (pos>1 && pos<=cnt)
    {
        ptr = first;
        for (i = 1;i < pos;i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = newnode;
        newnode->next = ptr;
        printf("\nELEMNT IS INSERTED");
    }
    else
    {
        printf("Position is out of range");
    }
}
 
void delete_pos()    //delete an element at any position
{
    int pos, cnt = 0, i;
 
    if (first == NULL)
    {
        printf("\nEMPTY LIST");
    }
    else
    {
        printf("\nEnter the position of value to be deleted:");
        scanf(" %d", &pos);
        ptr = first;
        if (pos == 1)
        {
            first = ptr->next;
            printf("\nELEMENT IS DELETED");    
        }
        else 
        {
            while (ptr != NULL)
            {
                ptr = ptr->next;
                cnt = cnt + 1;
            }
            if (pos > 0 && pos <= cnt)    
            {
                ptr = first;
                for (i = 1;i < pos;i++)
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
                prev->next = ptr->next;
            }
            else
            {
                printf("Position is out of range");
            }
        free(ptr);
        printf("\nELEMENT IS DELETED");
        }
    }
}

void display()  //display the linked list
{
    if (first == NULL)
    {
        printf("\nEMPTY LIST");
    }
    else
    {
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {    
            printf("%d\t", ptr->data);
        }
    }
}
 


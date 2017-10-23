/*
queue
*/
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>   //dynamic memory allocation

#define MAX 10
 
struct node
{
    int data;
    struct node *link;
}*front, *rear;

void insert();
void delete();
void display();
 
void main()
{
    int choice,value;
 
    while(1)
    {
        printf("Enter the choice \n");
        printf("1 : Insert an element \n");
        printf("2 : Delete an element \n");
        printf("3 : Display the queue\n");
        printf("4 : Exit\n");
        scanf("%d", &choice);
        switch (choice)    
        {
       case 1:    
            insert();
            break;
        case 2: 
            delete();
            break;
        case 3: 
            display();
            break;
        case 4: 
            exit(0);
        default: 
            printf("You have entered a wrong choice\n");
            break;
        }
    }
}
void insert()   //insert an element
{
    struct node *temp;
 
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter value to be inserted \n");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (rear  ==  NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }    
}
void delete()    //delete an element
{
    struct node *temp;
 
    temp = front;
    if (front == NULL)
    {
        printf("Queue is empty \n");
        front = rear = NULL;
    }
    else
    {    
        printf("Deleted element is %d\n", front->data);
        front = front->link;
        free(temp);
    }
}
void display()
{
    struct node *temp;
 
    temp = front;
    int count = 0;
    if (front  ==  NULL)
    {
        printf("Queue is underflow\n");
    }
    while (temp)
    {
        printf("%d  ", temp->data);
        temp = temp->link;
        count++;
    }
}

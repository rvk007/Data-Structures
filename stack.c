/*
Stack-push and pop
*/
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>  //dynamic memory allocation

struct node
{
    int data;
    struct node *link;
}*top = NULL;
 
#define MAX 10
 
void push();
void pop();
void display();
 
void main()
{
    int choice;
 
    while (1)
    {
        printf("Please enter your choice \n");
        printf("1. Push an element \n");
        printf("2. Pop an element \n");
        printf("3. Display \n");
        printf("4. Exit \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:    
            push();
            break;         
        case 2:    
            pop();
            break;         
        case 3:    
            display();
            break;         
        case 4:    
            exit(0);
        default:
            printf("You have entered a wrong choice\n");         
        }
    }
}
void push()    //insert an element
{
    int value,count;
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
 
    
    if (count <= MAX - 1)
    {
        printf("\nEnter value which you want to insert into the stack :\n");
        scanf("%d",&value);
        temp->data = value;
        temp->link = top;
        top = temp;
    }
    else
        printf("STACK OVERFLOW\n");
}

void pop()    //delete an element
{
    struct node *temp;
    if (top == NULL)
        printf("Stack is empty\n");
    else
    {
        temp = top;
        printf("Value popped out is %d \n",temp->data);
        top = top->link;
        free(temp);
    }
}
void display()  //display the stack
{
    int count = 0;
    struct node *temp;
 
    temp = top;
    while (temp != NULL)
    {
        printf(" %d\n",temp->data);
        temp = temp->link;
        count++;
    }
}

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    struct node *new_n;
    int d;

    new_n = (struct node *)malloc(sizeof(struct node));

    printf("\n Enter element:");
    scanf("%d", &d);

    new_n->data = d;
    new_n->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = new_n;
    }
    else
    {
        rear->next = new_n;
        
    }
}

void dequeue()
{
    struct node *temp;
    temp = front;

    if ((front == NULL) && (rear == NULL))
    {
        printf("\n Queue is Empty");
    }
    else
    {
        printf("\n deleted node is %d", front->data);
      
        front = front->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;

    if (front == NULL && rear == NULL)
    {
        printf("\n Queue is Empty");
    }
    else
    {
        temp = front;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

void main()
{
    int ch;

    while (1)
    {
        printf("\n\t\t\t queue operations are:");
        printf("\n\t\t\t\t 1.insert");
        printf("\nt\t\t\t 2.delete");
        printf("\nt\t\t\t 3.display");
        printf("\n Enter your choice:");

        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("\n Invalid choice, try again");
        }
    }
}

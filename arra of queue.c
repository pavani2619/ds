
#include <stdio.h>
#include <stdlib.h>

int queue[100], n, i, front = -1, rear = -1, x, ch;

void insert();
void deleteElement();
void display();

int main()
{
    printf("Enter queue size: ");
    scanf("%d", &n);

    printf("Queue operations: 1. Insert 2. DeleteElement 3. Display 4. Exit");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            deleteElement();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exit from queue");
            exit(0);

        default:
            printf("Invalid choice");
        }
    }
}

void insert()
{
    if (rear == n - 1)
    {
        printf("Queue is full");
    }
    else
    {
        rear++;
        printf("Enter queue element: ");
        scanf("%d", &x);
        queue[rear] = x;
        printf("Element inserted");
    }
}

void deleteElement()
{
    if (front >= rear)
    {
        printf("Queue is empty");
    }
    else
    {
        front++;
        printf("Deleted data element is %d", queue[front]);
    }
}

void display()
{
    if (front >= rear)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Queue elements are:\n");
        for (i = front + 1; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

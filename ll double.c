#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *llink, *rlink;
};

struct node *start = NULL, *last = NULL;

// Insert at beginning
void firstinsert()
{
    struct node *temp;
    int e;

    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter element to store in node: ");
    scanf("%d", &e);

    temp->data = e;
    temp->llink = NULL;
    temp->rlink = NULL;

    if (start == NULL)
    {
        start = last = temp;
    }
    else
    {
        temp->rlink = start;
        start->llink = temp;
        start = temp;
    }
}

// Insert at end
void lastinsert()
{
    struct node *temp;
    int e;

    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter an element to store in node: ");
    scanf("%d", &e);

    temp->data = e;
    temp->llink = NULL;
    temp->rlink = NULL;

    if (start == NULL)
    {
        start = last = temp;
    }
    else
    {
        last->rlink = temp;
        temp->llink = last;
        last = temp;
    }
}

// Insert at position
void middleinsert()
{
    struct node *temp, *t1;
    int e, pos, i = 1;

    printf("\nEnter the position to insert: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        firstinsert();
        return;
    }

    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter element to store in node: ");
    scanf("%d", &e);

    temp->data = e;
    temp->llink = NULL;
    temp->rlink = NULL;

    t1 = start;

    while (i < pos - 1 && t1 != NULL)
    {
        t1 = t1->rlink;
        i++;
    }

    if (t1 == NULL)
    {
        printf("\n inside of middle insert fun");
        free(temp);
        return;
    }

    temp->rlink = t1->rlink;
    temp->llink = t1;

    if (t1->rlink != NULL)
        t1->rlink->llink = temp;
    else
        last = temp;

    t1->rlink = temp;
}

// Delete first node
void firstdelete()
{
    struct node *temp;

    if (start == NULL)
    {
        printf("\nlinked list is empty,no nodes to perform delete operation");
        return;
    }

    temp = start;

    if (start == last)
    {
        start = last = NULL;
    }
    else
    {
        start = start->rlink;
        start->llink = NULL;
    }

    free(temp);
    printf("\nFirst node is deleted successfully");
}

// Delete last node
void lastdelete()
{
    struct node *temp;

    if (start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    temp = last;

    if (start == last)
    {
        start = last = NULL;
    }
    else
    {
        last = last->llink;
        last->rlink = NULL;
    }

    free(temp);
    printf("\nLast node is deleted successfully");
}

// Delete at position
void middledelete()
{
    struct node *t1;
    int pos, i = 1;

    printf("\nEnter the position to delete: ");
    scanf("%d", &pos);

    if (start == NULL)
    {
        printf("\n no elements to delete,linked list is empty");
        return;
    }

    if (pos == 1)
    {
        firstdelete();
        return;
    }

    t1 = start;

    while (i < pos && t1 != NULL)
    {
        t1 = t1->rlink;
        i++;
    }

    if (t1 == NULL)
    {
        printf("\nPosition out of range");
        return;
    }

    if (t1->rlink != NULL)
        t1->rlink->llink = t1->llink;
    else
        last = t1->llink;

    if (t1->llink != NULL)
        t1->llink->rlink = t1->rlink;

    free(t1);
    printf("\nNode deleted");
}

// Display list
void display()
{
    struct node *t1;

    if (start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    printf("\nForward:\n");
    t1 = start;
    while (t1 != NULL)
    {
        printf("%d ", t1->data);
        t1 = t1->rlink;
    }

    printf("\nBackward:\n");
    t1 = last;
    while (t1 != NULL)
    {
        printf("%d ", t1->data);
        t1 = t1->llink;
    }
}

// Main function
int main()
{
    int ch;

    while (1)
    {
        printf("\n\n--- Doubly Linked List ---");
        printf("\n1. first insert");
        printf("\n2. Last insert");
        printf("\n3. middle insert");
        printf("\n4. first delete");
        printf("\n5. last delete");
        printf("\n6. middle delete");
        printf("\n7. Display");
        printf("\n8. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            firstinsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            middleinsert();
            break;
        case 4:
            firstdelete();
            break;
        case 5:
            lastdelete();
            break;
        case 6:
            middledelete();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *Start = NULL, *temp, *last, *t1, *t2;

void Firstinsert() {
    int e;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\n\tEnter an element to store in node: ");
    scanf("%d", &e);
    temp->data = e;
    temp->link = NULL;

    if (Start == NULL) {
        Start = temp;
        last = temp;
    } else {
        temp->link = Start;
        Start = temp;
    }
}

void lastinsert() {
    int e;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\n\tEnter an element to store in node: ");
    scanf("%d", &e);
    temp->data = e;
    temp->link = NULL;

    if (Start == NULL) {
        Start = temp;
        last = temp;
    } else {
        last->link = temp;
        last = temp;
    }
}

void middleinsert() {
    int e, pos, i = 1;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\n\tEnter an element to store in node: ");
    scanf("%d", &e);
    temp->data = e;
    temp->link = NULL;

    printf("\n\tEnter the position to insert: ");
    scanf("%d", &pos);

    if (Start == NULL) {
        Start = temp;
    } else {
        t1 = Start;
        while (i < pos - 1) {
            t1 = t1->link;
            i++;
        }
        temp->link = t1->link;
        t1->link = temp;
    }
}

void Firstdelete() {
    if (Start == NULL) {
        printf("\n\t Linked List is empty, No nodes to perform");
    } else {
        Start = Start->link;
        printf("\n\t 1st Node is deleted operation");
    }
}

void lastdelete() {
    if (Start == NULL) {
        printf("\n\t No nodes in linked list to delete");
    } else if (Start->link == NULL) {
        Start = NULL;
    } else {
        t1 = Start;
        while (t1->link != NULL) {
            t2 = t1;
            t1 = t1->link;
        }
        t2->link = NULL;
        last = t2;
    }
}

void middledelete() {
    int pos, i = 1;
    printf("\n Enter the position to delete the node: ");
    scanf("%d", &pos);

    if (Start == NULL) {
        printf("\n\t No element to delete");
    } else {
        t1 = Start;
        while (i < pos) {
            t2 = t1;
            t1 = t1->link;
            i++;
        }
        t2->link = t1->link;
    }
}

void disp() {
    if (Start == NULL) {
        printf("\n\t No elements in linked list...");
    } else {
        printf("\n\t Linked list elements are... ");
        temp = Start;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n\t--- Linked List Operations ---");
        printf("\n\t 1. First Insert");
        printf("\n\t 2. Last Insert");
        printf("\n\t 3. Middle Insert");
        printf("\n\t 4. First Delete");
        printf("\n\t 5. Last Delete");
        printf("\n\t 6. Middle Delete");
        printf("\n\t 7. Display");
        printf("\n\t 8. Exit");
        printf("\n\t Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: Firstinsert(); break;
            case 2: lastinsert(); break;
            case 3: middleinsert(); break;
            case 4: Firstdelete(); break;
            case 5: lastdelete(); break;
            case 6: middledelete(); break;
            case 7: disp(); break;
            case 8: exit(0); break;
            default: printf("\n Invalid choice!");
        }
    }
    return 0;
}

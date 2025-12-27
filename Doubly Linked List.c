#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* prev;
    struct node* next;
};

struct node* start = NULL;


void create(int item) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->info = item;
    p->prev = NULL;
    p->next = NULL;

    if (start == NULL) {
        start = p;
        return;
    }

    struct node* temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = p;
    p->prev = temp;
}

void insertLeft(int item, int value) {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = start;


    while (temp != NULL && temp->info != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found in the list!\n", value);
        return;
    }

    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->info = item;


    p->prev = temp->prev;
    p->next = temp;

    if (temp->prev != NULL)
        temp->prev->next = p;
    else
        start = p;

    temp->prev = p;
}


void deleteByValue(int value) {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = start;

    while (temp != NULL && temp->info != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found!\n", value);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        start = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node with value %d deleted.\n", value);
}


void display() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = start;
    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, item, key;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Create (Insert at End)\n");
        printf("2. Insert Left of Value\n");
        printf("3. Delete Node by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                create(item);
                break;

            case 2:
                printf("Enter new element: ");
                scanf("%d", &item);
                printf("Insert to the left of value: ");
                scanf("%d", &key);
                insertLeft(item, key);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteByValue(key);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

struct node* stack = NULL;
struct node* queue = NULL;
void push(int item) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->info = item;
    p->next = stack;
    stack = p;
    printf("%d pushed into stack.\n", item);
}

void pop() {
    if (stack == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    struct node* temp = stack;
    printf("%d popped from stack.\n", stack->info);
    stack = stack->next;
    free(temp);
}

// -------------------------------
// Display Stack
// -------------------------------
void displayStack() {
    if (stack == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    struct node* temp = stack;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}


void enqueue(int item) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->info = item;
    p->next = NULL;

    if (queue == NULL) {
        queue = p;
    } else {
        struct node* temp = queue;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }

    printf("%d enqueued into queue.\n", item);
}

// Delete from beginning (Dequeue)
void dequeue() {
    if (queue == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct node* temp = queue;
    printf("%d dequeued from queue.\n", queue->info);
    queue = queue->next;
    free(temp);
}


void displayQueue() {
    if (queue == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct node* temp = queue;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                printf("Enter element: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 5:
                dequeue();
                break;

            case 6:
                displayQueue();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

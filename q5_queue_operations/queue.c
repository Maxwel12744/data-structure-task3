/*
 * Question 5: Enqueue and dequeue operations in a queue (array based)
 *
 * A queue follows FIFO: First In, First Out.
 *   - enqueue adds an item at the REAR (back)
 *   - dequeue removes an item from the FRONT
 *
 * front and rear are both -1 when the queue is empty.
 */

#include <stdio.h>

#define SIZE 5                 /* maximum number of items the queue can hold */

int queue[SIZE];
int front = -1;                /* index of the first item */
int rear = -1;                 /* index of the last item */

/* The queue is empty when front is still -1 */
int isEmpty(void)
{
    return front == -1;
}

/* The queue is full when rear has reached the last index */
int isFull(void)
{
    return rear == SIZE - 1;
}

/* Add a value at the rear of the queue */
void enqueue(int value)
{
    if (isFull()) {
        printf("Queue overflow: the queue is full, cannot add %d.\n", value);
        return;
    }

    if (isEmpty())             /* first item: front starts at index 0 */
        front = 0;

    rear++;
    queue[rear] = value;
    printf("%d was added to the queue.\n", value);
}

/* Remove the value at the front of the queue */
void dequeue(void)
{
    if (isEmpty()) {
        printf("Queue underflow: the queue is empty, nothing to remove.\n");
        return;
    }

    int value = queue[front];
    printf("%d was removed from the queue.\n", value);

    if (front == rear) {       /* that was the last item, so reset the queue */
        front = -1;
        rear = -1;
    } else {
        front++;               /* otherwise move front to the next item */
    }
}

/* Show every item from front to rear */
void display(void)
{
    if (isEmpty()) {
        printf("The queue is empty.\n");
        return;
    }

    printf("Queue (front to rear): ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main(void)
{
    int choice, value;

    do {
        printf("\n===== QUEUE MENU =====\n");
        printf("1. Enqueue (add an item)\n");
        printf("2. Dequeue (remove an item)\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("That was not a number. Exiting.\n");
            break;
        }

        switch (choice) {
        case 1:
            printf("Enter the value to add: ");
            if (scanf("%d", &value) == 1)
                enqueue(value);
            else
                printf("Invalid value.\n");
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Goodbye.\n");
            break;
        default:
            printf("Invalid choice, please pick 1 to 4.\n");
        }
    } while (choice != 4);

    return 0;
}
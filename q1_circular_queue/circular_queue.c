/*
 * CCS 2214 - Data Structures and Algorithms
 * Task 3, Question 1: Circular Queue
 * Author: Maxwel Ochieng Odhiambo
 * Registration number: CIT-223-083/2025
 *
 * DISADVANTAGES OF A LINEAR QUEUE
 * 1. Wasted space: when an item is removed, front moves forward and the
 *    freed slot at the start of the array can never be used again.
 * 2. False overflow: the queue says "full" when rear reaches the last
 *    index, even if there are empty slots at the front.
 * 3. Poor use of memory: after many enqueue and dequeue operations, most
 *    of the array can be unusable even though the queue holds few items.
 * 4. Shifting is slow: the only way to get the lost space back is to shift
 *    every item to the left, which takes O(n) time.
 * 5. Fixed size: with an array, the capacity cannot grow.
 *
 * HOW A CIRCULAR QUEUE FIXES THIS
 * The array is treated as a circle. When front or rear reaches the end,
 * it wraps around to index 0 using the % operator, so every freed slot
 * can be used again. Enqueue and dequeue both stay O(1).
 */

#include <stdio.h>

#define SIZE 5                 /* maximum number of items in the queue */

int queue[SIZE];
int front = 0;                 /* index of the first item */
int rear = -1;                 /* index of the last item */
int count = 0;                 /* how many items are in the queue */

int isFull(void)
{
    return count == SIZE;
}

int isEmpty(void)
{
    return count == 0;
}

/* Add a value at the rear. rear wraps around to 0 after the last index. */
void enqueue(int value)
{
    if (isFull()) {
        printf("Queue is full (overflow). Cannot insert %d.\n", value);
        return;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    count++;
    printf("%d inserted.\n", value);
}

/* Remove the value at the front. front wraps around to 0 after the last index. */
void dequeue(void)
{
    if (isEmpty()) {
        printf("Queue is empty (underflow). Nothing to remove.\n");
        return;
    }

    printf("%d removed.\n", queue[front]);
    front = (front + 1) % SIZE;
    count--;
}

/* Show the value at the front without removing it */
void peek(void)
{
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front element is %d.\n", queue[front]);
}

/* Show all items from front to rear, wrapping around the end of the array */
void display(void)
{
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue (front to rear): ");
    for (int i = 0; i < count; i++)
        printf("%d ", queue[(front + i) % SIZE]);
    printf("\n");
}

int main(void)
{
    int choice, value;

    do {
        printf("\n===== CIRCULAR QUEUE (size %d) =====\n", SIZE);
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("That was not a number. Exiting.\n");
            break;
        }

        switch (choice) {
        case 1:
            printf("Enter a value: ");
            if (scanf("%d", &value) == 1)
                enqueue(value);
            else
                printf("Invalid value.\n");
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Goodbye.\n");
            break;
        default:
            printf("Invalid choice, please pick 1 to 5.\n");
        }
    } while (choice != 5);

    return 0;
}
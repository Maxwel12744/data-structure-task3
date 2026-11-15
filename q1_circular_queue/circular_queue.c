/*
 * CCS 2214 - Data Structures and Algorithms
 * Task 3, Question 1: Circular Queue
 * Author: Maxwel Ochieng Odhiambo
 *
 * DISADVANTAGES OF A LINEAR QUEUE
 * 1. Wasted space: when an element is dequeued, the front moves forward
 *    and the freed slot at the start of the array can never be used again.
 * 2. False overflow: the queue reports "full" when rear reaches the last
 *    index, even if there are empty slots at the front.
 * 3. Poor memory utilisation: after many enqueue and dequeue operations,
 *    most of the array can be unusable although the queue holds few items.
 * 4. Shifting is expensive: the only way to recover the lost space is to
 *    shift all elements to the left, which takes O(n) time per operation.
 * 5. Fixed size: when implemented with an array, the capacity cannot grow.
 *
 * HOW A CIRCULAR QUEUE FIXES THIS
 * The array is treated as a circle. When rear or front reaches the end,
 * it wraps around to index 0 using the modulus operator, so every freed
 * slot can be reused. Enqueue and dequeue both stay O(1).
 */

#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = 0;   /* index of the first element */
int rear = -1;   /* index of the last element */
int count = 0;   /* number of elements in the queue */

int isFull(void) {
    return count == SIZE;
}

int isEmpty(void) {
    return count == 0;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full (overflow). Cannot insert %d.\n", value);
        return;
    }
    rear = (rear + 1) % SIZE;   /* wrap around to 0 after the last index */
    queue[rear] = value;
    count++;
    printf("%d inserted.\n", value);
}

void dequeue(void) {
    if (isEmpty()) {
        printf("Queue is empty (underflow). Nothing to remove.\n");
        return;
    }
    int value = queue[front];
    front = (front + 1) % SIZE; /* wrap around to 0 after the last index */
    count--;
    printf("%d removed.\n", value);
}

void peek(void) {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element is %d.\n", queue[front]);
}

void display(void) {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue (front to rear): ");
    for (int i = 0; i < count; i++) {
        printf("%d ", queue[(front + i) % SIZE]);
    }
    printf("\n");
}

int main(void) {
    int choice, value;

    do {
        printf("\n--- CIRCULAR QUEUE (size %d) ---\n", SIZE);
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter a value: ");
                if (scanf("%d", &value) == 1) {
                    enqueue(value);
                }
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
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
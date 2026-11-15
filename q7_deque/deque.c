/*
 * Question 7: Operations on a double ended queue (deque)
 *
 * A deque lets us insert and delete at BOTH ends:
 *   - front insertion      - rear insertion
 *   - front deletion       - rear deletion
 *
 * It is stored in a circular array. 'front' is the index of the first
 * item and 'count' is how many items are stored, so:
 *   the rear item is at index (front + count - 1) % SIZE
 * The % SIZE makes the index wrap around to the other end of the array.
 */

#include <stdio.h>

#define SIZE 5

int deque[SIZE];
int front = 0;                 /* index of the first item */
int count = 0;                 /* number of items currently stored */

int isEmpty(void)
{
    return count == 0;
}

int isFull(void)
{
    return count == SIZE;
}

/* 1. Front insertion: move front one step back, then store the value */
void insertFront(int value)
{
    if (isFull()) {
        printf("Deque overflow: cannot insert %d at the front.\n", value);
        return;
    }

    front = (front - 1 + SIZE) % SIZE;   /* + SIZE avoids a negative index */
    deque[front] = value;
    count++;
    printf("%d inserted at the front.\n", value);
}

/* 2. Rear insertion: store the value just after the current last item */
void insertRear(int value)
{
    if (isFull()) {
        printf("Deque overflow: cannot insert %d at the rear.\n", value);
        return;
    }

    int rear = (front + count) % SIZE;   /* first free slot after the last item */
    deque[rear] = value;
    count++;
    printf("%d inserted at the rear.\n", value);
}

/* 3. Front deletion: take the first item and move front forward */
void deleteFront(void)
{
    if (isEmpty()) {
        printf("Deque underflow: nothing to delete from the front.\n");
        return;
    }

    printf("%d deleted from the front.\n", deque[front]);
    front = (front + 1) % SIZE;
    count--;
}

/* 4. Rear deletion: take the last item; front does not move */
void deleteRear(void)
{
    if (isEmpty()) {
        printf("Deque underflow: nothing to delete from the rear.\n");
        return;
    }

    int rear = (front + count - 1) % SIZE;   /* index of the last item */
    printf("%d deleted from the rear.\n", deque[rear]);
    count--;
}

/* Show the items from front to rear */
void display(void)
{
    if (isEmpty()) {
        printf("The deque is empty.\n");
        return;
    }

    printf("Deque (front to rear): ");
    for (int i = 0; i < count; i++)
        printf("%d ", deque[(front + i) % SIZE]);
    printf("\n");
}

int main(void)
{
    int choice, value;

    do {
        printf("\n===== DOUBLE ENDED QUEUE MENU =====\n");
        printf("1. Insert at the front\n");
        printf("2. Insert at the rear\n");
        printf("3. Delete from the front\n");
        printf("4. Delete from the rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("That was not a number. Exiting.\n");
            break;
        }

        switch (choice) {
        case 1:
            printf("Enter the value: ");
            if (scanf("%d", &value) == 1)
                insertFront(value);
            else
                printf("Invalid value.\n");
            break;
        case 2:
            printf("Enter the value: ");
            if (scanf("%d", &value) == 1)
                insertRear(value);
            else
                printf("Invalid value.\n");
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Goodbye.\n");
            break;
        default:
            printf("Invalid choice, please pick 1 to 6.\n");
        }
    } while (choice != 6);

    return 0;
}
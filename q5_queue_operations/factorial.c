/*
 * Question 4(b): Factorial of a number using recursion
 *
 * Idea: n! = n * (n - 1)!, and 0! = 1! = 1.
 * Example: 5! = 5 * 4 * 3 * 2 * 1 = 120
 */

#include <stdio.h>

/* Returns n factorial. long long is used because factorials grow fast. */
long long factorial(int n)
{
    if (n == 0 || n == 1)              /* base case */
        return 1;

    return n * factorial(n - 1);       /* recursive case */
}

int main(void)
{
    int n;

    printf("Enter a number: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Factorial is only defined for whole numbers that are 0 or more.\n");
        return 1;
    }

    /* 21! is too big for a long long, so we stop at 20 */
    if (n > 20) {
        printf("That number is too large. Please enter 20 or less.\n");
        return 1;
    }

    printf("%d! = %lld\n", n, factorial(n));
    return 0;
}
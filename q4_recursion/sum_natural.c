/*
 * Question 4(a): Sum of the first N natural numbers using recursion
 *
 * Idea: sum(N) = N + sum(N - 1), and sum(0) = 0.
 * Example: sum(4) = 4 + 3 + 2 + 1 + 0 = 10
 */

#include <stdio.h>

/* Returns 1 + 2 + ... + n */
int sum(int n)
{
    if (n == 0)                 /* base case: nothing left to add */
        return 0;

    return n + sum(n - 1);      /* recursive case: n plus the sum of the rest */
}

int main(void)
{
    int n;

    printf("Enter N: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Please enter a whole number that is 0 or more.\n");
        return 1;
    }

    printf("The sum of the first %d natural numbers is %d\n", n, sum(n));
    return 0;
}
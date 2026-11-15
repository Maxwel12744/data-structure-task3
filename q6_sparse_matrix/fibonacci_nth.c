/*
 * Question 4(c): Nth term of the Fibonacci series using recursion
 *
 * The series is: 0, 1, 1, 2, 3, 5, 8, 13, ...
 * Each term is the sum of the two terms before it.
 * So the 1st term is 0, the 2nd term is 1, the 7th term is 8.
 */

#include <stdio.h>

/* Returns the nth term of the Fibonacci series (counting from 1) */
int fib(int n)
{
    if (n == 1)                        /* base case: first term */
        return 0;
    if (n == 2)                        /* base case: second term */
        return 1;

    return fib(n - 1) + fib(n - 2);    /* add the two previous terms */
}

int main(void)
{
    int n;

    printf("Enter N (1 or more): ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Please enter a whole number that is 1 or more.\n");
        return 1;
    }

    /* This method gets slow for large n, so we limit it for a quick demo */
    if (n > 40) {
        printf("Please enter 40 or less, larger values take too long.\n");
        return 1;
    }

    printf("Term number %d of the Fibonacci series is %d\n", n, fib(n));
    return 0;
}
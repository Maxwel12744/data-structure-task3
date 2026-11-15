/*
 * Question 4(d): Generate N terms of the Fibonacci series using recursion
 *
 * We carry the current term (a) and the next term (b) along with us.
 * Each call prints a, then moves forward: the new current term is b,
 * and the new next term is a + b.
 */

#include <stdio.h>

/* Prints 'count' terms of the series, starting from the pair (a, b) */
void series(int count, long long a, long long b)
{
    if (count == 0)                    /* base case: no terms left to print */
        return;

    printf("%lld ", a);                /* print the current term */
    series(count - 1, b, a + b);       /* move one step forward */
}

int main(void)
{
    int n;

    printf("Enter the number of terms: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Please enter a whole number that is 1 or more.\n");
        return 1;
    }

    /* 90 terms is the most that fits safely in a long long */
    if (n > 90) {
        printf("Please enter 90 or less.\n");
        return 1;
    }

    printf("First %d terms of the Fibonacci series:\n", n);
    series(n, 0, 1);                   /* the series starts with 0 and 1 */
    printf("\n");
    return 0;
}
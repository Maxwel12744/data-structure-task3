/*
 * Question 6: Represent a sparse matrix using arrays
 *
 * A sparse matrix is a matrix in which most elements are zero.
 * Storing every zero wastes memory, so we store only the non-zero
 * elements in a 3-column array (the "triplet" form):
 *
 *      Row | Column | Value
 *
 * The first row of this array is a header that holds:
 *      total rows | total columns | number of non-zero values
 */

#include <stdio.h>

#define MAX 10                          /* largest matrix size is 10 x 10 */

int main(void)
{
    int matrix[MAX][MAX];               /* the normal 2D matrix */
    int sparse[MAX * MAX + 1][3];       /* the triplet (sparse) form */
    int rows, cols;
    int i, j, k;

    printf("Enter the number of rows (1 to %d): ", MAX);
    if (scanf("%d", &rows) != 1 || rows < 1 || rows > MAX) {
        printf("Invalid number of rows.\n");
        return 1;
    }

    printf("Enter the number of columns (1 to %d): ", MAX);
    if (scanf("%d", &cols) != 1 || cols < 1 || cols > MAX) {
        printf("Invalid number of columns.\n");
        return 1;
    }

    /* Read the matrix one element at a time */
    printf("Enter the %d elements of the matrix:\n", rows * cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid element.\n");
                return 1;
            }
        }
    }

    /* Go through the matrix and copy only the non-zero values.
     * k starts at 1 because row 0 is kept for the header. */
    k = 1;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;               /* row number */
                sparse[k][1] = j;               /* column number */
                sparse[k][2] = matrix[i][j];    /* the value itself */
                k++;
            }
        }
    }

    /* Fill in the header row */
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1;                       /* count of non-zero values */

    /* Show the original matrix */
    printf("\nOriginal matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }

    /* Show the sparse representation */
    printf("\nSparse matrix (triplet form):\n");
    printf("%4s %7s %6s\n", "Row", "Column", "Value");
    printf("%4d %7d %6d   <- header: rows, columns, non-zero count\n",
           sparse[0][0], sparse[0][1], sparse[0][2]);
    for (i = 1; i < k; i++)
        printf("%4d %7d %6d\n", sparse[i][0], sparse[i][1], sparse[i][2]);

    /* Compare the memory used by both forms.
     * The sparse form stores 3 numbers per non-zero value, plus the header. */
    printf("\nMemory comparison:\n");
    printf("Normal matrix : %d values stored\n", rows * cols);
    printf("Sparse form   : %d values stored\n", k * 3);

    if (k * 3 < rows * cols)
        printf("The sparse form uses less memory for this matrix.\n");
    else
        printf("This matrix has too many non-zero values, so the sparse form "
               "does not save memory.\n");
    printf("(The sparse form pays off when most of the matrix is zero.)\n");

    return 0;
}
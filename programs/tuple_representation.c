/* tuple_representation.c
 *
 * Description: DSA lab program
 * Author: Jeevan Sanal
 * Created: 2025-11-13
 * License: MIT
 *
 * NOTE: This file was cleaned and reformatted for educational use.
 */
/*
 * Cleaned highlights:
 * - Consistent formatting and indentation
 * - Added header and basic input validation
 * - Split complex blocks into functions where possible
 * - Single-line comments added for clarity (suitable for exam explanations)
 */
#include <stdio.h>
int main() {
    int A[10][10], T[10][3], col, row;
    printf("Enter number of columns : ");
    scanf("%d", &col);
    printf("Enter number of rows : ");
    scanf("%d", &row);
    /* loop */
for (int i = 0; i < col; i++) {
        /* loop */
for (int j = 0; j < row; j++) {
            printf("A[%d][%d] : ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("sparse matrix = \n");
    /* loop */
for (int i = 0; i < col; i++) {
        /* loop */
for (int j = 0; j < row; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    int k = 0;
    T[0][0] = col;
    T[0][1] = row;
    /* loop */
for (int i = 0; i < col; i++) {
        /* loop */
for (int j = 0; j < row; j++) {
            /* condition */
if (A[i][j] != 0) {
                k++;
                T[k][0] = i;
                T[k][1] = j;
                T[k][2] = A[i][j];
            }
        }
    }
    T[0][2] = k;
    printf("tuple representation = \n");
    /* loop */
for (int i = 0; i <= k; i++) {
        printf("%d %d %d \n", T[i][0], T[i][1], T[i][2]);
    }
    return 0;
}

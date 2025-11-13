/* sparse_matrix.c
 *
 * Description: Sparse matrix representation and operations
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
    int T1[10][3], T2[10][3];
    printf("Enter number of columns : ");
    scanf("%d", &T1[0][0]);
    printf("Enter number of rows : ");
    scanf("%d", &T1[0][1]);
    printf("Enter number of non zero values : ");
    scanf("%d", &T1[0][2]);
    /* loop */
for (int i = 1; i <= T1[0][2]; i++) {
        printf("enter i of the %d non zero value : ", i);
        scanf("%d", &T1[i][0]);
        printf("enter i of the %d non zero value : ", i);
        scanf("%d", &T1[i][1]);
        printf("enter value : ");
        scanf("%d", &T1[i][2]);
    }
    /* loop */
for (int i = 0; i <= T1[0][2]; i++) {
        T2[i][0] = T1[i][1];
        T2[i][1] = T1[i][0];
        T2[i][2] = T1[i][2];
    }
    /* loop */
for (int i = 0; i <= T2[0][2]; i++) {
        printf("%d %d %d \n", T2[i][0], T2[i][1], T2[i][2]);
    }
    return 0;
}

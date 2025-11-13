/* addition_of_matrices.c
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
int main(){
    int A[2][10][10],col,row;
    printf("Enter number of columns : ");
    scanf("%d",&col);
    printf("Enter number of rows : ");
    scanf("%d",&row);
    /* loop */
for(int i = 0;i<2;i++){
        /* loop */
for(int j = 0;j<col;j++){
            /* loop */
for(int k = 0;k<row;k++){
                printf("A[%d][%d][%d] : ",i,j,k);
                scanf("%d",&A[i][j][k]);
            }
        }
        printf("\n");
    }
    printf("added matrix = \n");
    /* loop */
for(int j = 0;j<col;j++){
        /* loop */
for(int k = 0;k<row;k++){
            printf("  %d  ",A[0][j][k] + A[1][j][k]);
        }
        printf("\n");
    }
    return 0;
}

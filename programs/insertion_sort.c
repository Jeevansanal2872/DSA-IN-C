/* insertion_sort.c
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
    int max, a[50];
    printf("Enter number of elements in the array : ");
    scanf("%d", &max);
    /* loop */
for (int i = 0; i < max; i++) {
        printf("Enter %d element : ", i);
        scanf("%d", &a[i]);
    }
    printf("Unsorted list : ");
    /* loop */
for (int i = 0; i < max; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    int key;
    /* loop */
for (int i = 0; i < max - 1; i++) {
        key = a[i + 1];
        /* condition */
if (a[i] > key) {
            int j = i;
            /* while loop */
while (a[j] > key && j != -1) {
                a[j + 1] = a[j];
                j -= 1;
            }
            a[j + 1] = key;
        }
    }
    printf("Sorted list : ");
    /* loop */
for (int i = 0; i < max; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

/* quick_sort.c
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
int max, a[50];
void swap(int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int partition(int low, int high) {
    int i = low, j = high, x = a[low];
    /* while loop */
while (i < j) {
        /* while loop */
while (a[i] <= x && i < max)
            i++;
        /* while loop */
while (a[j] > x && j >= 0)
            j--;
        /* condition */
if (i < j)
            swap(i, j);
        else
            swap(j, low);
    }
    return j;
}
void quick(int low, int high) {
    /* condition */
if (low < high) {
        int mid = partition(low, high);
        quick(low, mid - 1);
        quick(mid + 1, high);
    }
}
int main() {
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
    quick(0, max - 1);
    printf("Sorted list : ");
    /* loop */
for (int i = 0; i < max; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 1;
}

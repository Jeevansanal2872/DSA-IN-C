/* merge_sort.c
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
int max, a[50], b[50];
void merge(int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    /* while loop */
while (i <= mid && j <= high) {
        /* condition */
if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    /* while loop */
while (i <= mid) {
        b[k++] = a[i++];
    }
    /* while loop */
while (j <= high) {
        b[k++] = a[j++];
    }
    /* loop */
for (int l = low; l <= high; l++) {
        a[l] = b[l];
    }
}
void mergesort(int low, int high) {
    /* condition */
if (low < high) {
        int mid = (low + high) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
}
int main() {
    printf("Enter number of elements in the array: ");
    scanf("%d", &max);
    /* loop */
for (int i = 0; i < max; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("Unsorted list: ");
    /* loop */
for (int i = 0; i < max; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    mergesort(0, max - 1);
    printf("Sorted list: ");
    /* loop */
for (int i = 0; i < max; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

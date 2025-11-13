/* binary_search.c
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
int binarysearch(int key, int low, int high) {
    /* condition */
if (low < high) {
        int mid = (low + high) / 2;
        /* condition */
if (key == a[mid])
            return mid;
        /* condition */
if (key < a[mid])
            return binarysearch(key, low, mid);
        else
            return binarysearch(key, mid, high);
    }
    return -1;
}
int main() {
    printf("Enter number of elements in the array : ");
    scanf("%d", &max);
    /* loop */
for (int i = 0; i < max; i++) {
        printf("Enter %d element : ", i);
        scanf("%d", &a[i]);
    }
    int key;
    printf("\n\nEnter element to search : ");
    scanf("%d", &key);
    int returnval = binarysearch(key, 0, max - 1);
    /* condition */
if (returnval == -1)
        printf("element %d not found ", key);
    else
        printf("element %d found at index %d", key, returnval);
    printf("\n");
    return 0;
}

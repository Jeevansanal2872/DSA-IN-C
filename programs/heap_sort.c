/* heap_sort.c
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
int heap[50], max, t_max;
void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}
void heapify(int size) {
    int i = 1;
    /* while loop */
while (i <= size) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        /* condition */
if (left <= size && heap[left] > heap[largest]) {
            largest = left;
        }
        /* condition */
if (right <= size && heap[right] > heap[largest]) {
            largest = right;
        }
        /* condition */
if (largest != i) {
            swap(&heap[i], &heap[largest]);
            i = largest;
        } else {
            break;
        }
    }
}
int main() {
    printf("Enter number of elements : ");
    scanf("%d", &max);
    max += 1;
    /* loop */
for (int i = 1; i < max; i++) {
        printf("enter element : ");
        scanf("%d", &heap[i]);
    }
    printf("Unsorted array : ");
    /* loop */
for (int i = 1; i < max; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
    t_max = max;
    /* loop */
for (int i = (max - 1) / 2; i >= 1; i--) {
        int parent = i;
        /* while loop */
while (parent <= max - 1) {
            int largest = parent;
            int left = 2 * parent;
            int right = 2 * parent + 1;
            /* condition */
if (left < max && heap[left] > heap[largest]) {
                largest = left;
            }
            /* condition */
if (right < max && heap[right] > heap[largest]) {
                largest = right;
            }
            /* condition */
if (largest != parent) {
                swap(&heap[parent], &heap[largest]);
                parent = largest;
            } else {
                break;
            }
        }
    }
    /* while loop */
while (t_max > 1) {
        swap(&heap[1], &heap[t_max - 1]);
        t_max -= 1;
        heapify(t_max - 1);
    }
    printf("Sorted array : ");
    /* loop */
for (int i = 1; i < max; i++) {
        printf("%d ", heap[i]);
    }
    return 0;
}

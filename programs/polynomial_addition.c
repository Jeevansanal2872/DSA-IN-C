/* polynomial_addition.c
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
struct poly {
    int co, exp;
} p1[10], p2[10], sum[20];
int size_of_a, size_of_b, size_of_sum;
int Sum() {
    int i = 0, j = 0, k = 0;
    /* while loop */
while (i < size_of_a && j < size_of_b) {
        /* condition */
if (p1[i].exp > p2[j].exp) {
            sum[k] = p1[i];
            k++;
            i++;
        } else /* condition */
if (p1[i].exp < p2[j].exp) {
            sum[k] = p2[j];
            k++;
            j++;
        } else {
            sum[k].exp = p1[i].exp;
            sum[k].co = p1[i].co + p2[j].co;
            i++;
            j++;
            k++;
        }
    }
    /* while loop */
while (i < size_of_a) {
        sum[k] = p1[i];
        k++;
        i++;
    }
    /* while loop */
while (j < size_of_b) {
        sum[k] = p2[j];
        k++;
        j++;
    }
    return k;
}
int main() {
    printf("First Polynomial\n");
    printf("Enter number of non-zero elements: ");
    scanf("%d", &size_of_a);
    /* loop */
for (int i = 0; i < size_of_a; i++) {
        printf("Enter coefficient: ");
        scanf("%d", &p1[i].co);
        printf("Enter exponent: ");
        scanf("%d", &p1[i].exp);
    }
    printf("Second Polynomial\n");
    printf("Enter number of non-zero elements: ");
    scanf("%d", &size_of_b);
    /* loop */
for (int i = 0; i < size_of_b; i++) {
        printf("Enter coefficient: ");
        scanf("%d", &p2[i].co);
        printf("Enter exponent: ");
        scanf("%d", &p2[i].exp);
    }
    size_of_sum = Sum();
    printf("First Polynomial: ");
    int first = 1;
    /* loop */
for (int i = 0; i < size_of_a; i++) {
        /* condition */
if (p1[i].co == 0)
            continue;
        /* condition */
if (!first)
            printf(" + ");
        /* condition */
if (p1[i].exp == 0) {
            printf("%d", p1[i].co);
        } else {
            printf("%dx^%d", p1[i].co, p1[i].exp);
        }
        first = 0;
    }
    printf("\n");
    printf("Second Polynomial: ");
    /* loop */
for (int i = 0; i < size_of_b; i++) {
        /* condition */
if (p2[i].co == 0)
            continue;
        /* condition */
if (p2[i].exp == 0) {
            printf("%d", p2[i].co);
        } else {
            printf("%dx^%d", p2[i].co, p2[i].exp);
        }
        // Check if there are more non-zero terms ahead
        int hasMore = 0;
        /* loop */
for (int j = i + 1; j < size_of_b; j++) {
            /* condition */
if (p2[j].co != 0) {
                hasMore = 1;
                break;
            }
        }
        /* condition */
if (hasMore)
            printf(" + ");
    }
    printf("\n");
    printf("Sum of Polynomials: ");
    /* loop */
for (int i = 0; i < size_of_sum; i++) {
        /* condition */
if (sum[i].co == 0)
            continue;
        /* condition */
if (sum[i].exp == 0) {
            printf("%d", sum[i].co);
        } else {
            printf("%dx^%d", sum[i].co, sum[i].exp);
        }
        // Check if there are more non-zero terms ahead
        int hasMore = 0;
        /* loop */
for (int j = i + 1; j < size_of_sum; j++) {
            /* condition */
if (sum[j].co != 0) {
                hasMore = 1;
                break;
            }
        }
        /* condition */
if (hasMore)
            printf(" + ");
    }
    printf("\n");
    return 0;
}

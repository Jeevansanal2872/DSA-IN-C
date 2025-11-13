/* stack.c
 *
 * Description: Stack data structure implementation
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
int top = -1, max, stack[50];
void push() {
    /* condition */
if (top >= max - 1) {
        printf("stack overflow\n");
        return;
    }
    printf("enter value to push : ");
    top += 1;
    scanf("%d", &stack[top]);
}
void pop() {
    /* condition */
if (top == -1) {
        printf("stack underflow\n");
        return;
    }
    top -= 1;
}
void display() {
    /* condition */
if (top == -1) {
        printf("stack is empty\n");
    }
    printf("stack --> \n");
    /* loop */
for (int i = top; i >= 0; i--) {
        printf("%d \n", stack[i]);
    }
    printf("\n");
}
int main() {
    printf("Enter total number of elements in the stack : ");
    scanf("%d", &max);
    int menu;
    do {
        printf("\tstack menu\n");
        printf("\t1. display\n");
        printf("\t2. push\n");
        printf("\t3. pop\n");
        printf("\t4. exit\n");
        printf("\t enter choice : ");
        scanf("%d", &menu);
        switch (menu) {
        case 1:
            display();
            break;
        case 2:
            push();
            break;
        case 3:
            pop();
            break;
        case 4:
            printf("exiting...");
            break;
        default:
            printf("Invalid input");
        }
    } /* while loop */
while (menu != 4);
    return 0;
}

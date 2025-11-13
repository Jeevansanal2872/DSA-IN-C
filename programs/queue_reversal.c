/* queue_reversal.c
 *
 * Description: Queue data structure (enqueue, dequeue) demonstration
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
int q[50], stack[50];
int top = -1, front = -1, rear = -1;
void push(int val) {
    /* condition */
if (top >= 50) {
        printf("stack overflow");
        return;
    }
    stack[++top] = val;
}
int pop() {
    /* condition */
if (top == -1) {
        printf("stack underflow");
        return -1;
    }
    return stack[top--];
}
void enqueue(int val) {
    /* condition */
if (rear >= 50) {
        printf("queue overflow");
    }
    /* condition */
if (front == -1 && rear == -1) {
        front = 0;
    }
    q[++rear] = val;
}
int dequque() {
    /* condition */
if (front == -1) {
        printf("queue underflow");
    }
    return q[front++];
}
void display_q() {
    /* loop */
for (int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}
void Reverse() {
    /* loop */
for (int i = front; i <= rear; i++) {
        push(dequque());
    }
    /* loop */
for (int i = top; i >= 0; i--) {
        enqueue(pop());
    }
}
int main() {
    printf("Enter number : ");
    int num, num2;
    scanf("%d", &num);
    /* loop */
for (int i = 0; i < num; i++) {
        printf("enter input : ");
        scanf("%d", &num2);
        enqueue(num2);
    }
    printf("initial queue");
    display_q();
    Reverse();
    printf("reversed queue");
    display_q();
    return 0;
}

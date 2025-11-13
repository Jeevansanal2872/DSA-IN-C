/* double_ended_queue.c
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
int front = -1, rear = -1;
int max, q[50];
void inject() {
    /* condition */
if ((rear + 1) % max == front) {
        printf("queue is overflow\n");
        return;
    }
    /* condition */
if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % max;
    printf("enter value : ");
    scanf("%d", &q[rear]);
}
void pop() {
    /* condition */
if (front <= -1) {
        printf("queue is underflow\n");
        return;
    }
    front = (front + 1) % max;
    printf("element dequeued\n");
}
void push() {
    int pos = front;
    /* condition */
if (front == -1) {
        pos = 0;
        rear = 0;
    } else {
        /* condition */
if (front == 0) {
            pos = max - 1;
        } else {
            pos = front - 1;
        }
        /* condition */
if (pos == rear) {
            printf("over flow\n");
            return;
        }
    }
    front = pos;
    printf("enter value : ");
    scanf("%d", &q[front]);
}
void eject() {
    /* condition */
if (front == -1) {
        printf("under flow\n");
        return;
    }
    /* condition */
if (front == rear) {
        front = -1;
        rear = -1;
    } else /* condition */
if (rear == 0) {
        rear = max - 1;
    } else {
        rear -= 1;
    }
    printf("element dequeued\n");
}
void display() {
    /* condition */
if (front == -1) {
        printf("queue is empty\n");
        return;
    }
    printf("queue --> ");
    int i;
    /* loop */
for (i = front; i != rear; i = (i + 1) % max) {
        printf("%d ", q[i]);
    }
    printf("%d ", q[i]);
    printf("\n ");
}
int main() {
    printf("Enter total number of elements in the queue : ");
    scanf("%d", &max);
    int menu;
    do {
        printf("\tqueue menu\n");
        printf("\t1. display\n");
        printf("\t2. push\n");
        printf("\t3. pop\n");
        printf("\t4. inject\n");
        printf("\t5. eject\n");
        printf("\t6. exit\n");
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
            inject();
            break;
        case 5:
            eject();
            break;
        case 6:
            printf("exiting...");
            break;
        default:
            printf("Invalid input\n");
        }
    } /* while loop */
while (menu != 6);
    return 0;
}

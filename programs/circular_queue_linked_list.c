/* circular_queue_linked_list.c
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
#include <stdlib.h>
struct Node {
    int data;
    struct Node *link;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void enqueue() {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    /* condition */
if (temp == NULL) {
        printf("queue is overflow\n");
        return;
    }
    printf("enter value : ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    /* condition */
if (front == NULL) {
        front = temp;
        rear = temp;
        rear->link = front;
    } else {
        rear->link = temp;
        rear = temp;
        rear->link = front;
    }
}
void dequeue() {
    /* condition */
if (front == NULL) {
        printf("queue is underflow\n");
        return;
    }
    struct Node *temp = front;
    /* condition */
if (front == rear) {
        front = NULL;
        rear = NULL;
    } else {
        front = front->link;
        rear->link = front;
    }
    free(temp);
    printf("element dequeued\n");
}
void display() {
    /* condition */
if (front == NULL) {
        printf("queue is empty\n");
        return;
    }
    printf("queue --> ");
    struct Node *temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->link;
    } /* while loop */
while (temp != front);
    printf("\n ");
}
int main() {
    int menu;
    do {
        printf("\tqueue menu\n");
        printf("\t1. display\n");
        printf("\t2. enqueue\n");
        printf("\t3. dequeue\n");
        printf("\t4. exit\n");
        printf("\t enter choice : ");
        scanf("%d", &menu);
        switch (menu) {
        case 1:
            display();
            break;
        case 2:
            enqueue();
            break;
        case 3:
            dequeue();
            break;
        case 4:
            printf("exiting...");
            break;
        default:
            printf("Invalid input\n");
        }
    } /* while loop */
while (menu != 4);
    return 0;
}

/* stack_linked_list.c
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
#include <stdlib.h>
struct Node {
    int data;
    struct Node *link;
} *head, *ptr, *temp;
void push() {
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->link = head->link;
    head->link = temp;
    printf("Enter value : ");
    scanf("%d", &temp->data);
}
void pop() {
    /* condition */
if (head->link == NULL) {
        printf("empty list");
        return;
    }
    ptr = head->link;
    head->link = ptr->link;
    free(ptr);
    printf("removed from frist\n");
}
void display() {
    temp = head->link;
    /* while loop */
while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}
void exit_linked_list() {
    ptr = head->link;
    /* while loop */
while (ptr != NULL) {
        temp = ptr->link;
        free(ptr);
        ptr = temp;
    }
    free(head);
    printf("exiting...\n");
}
int main() {
    int menu;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->link = NULL;
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
            exit_linked_list();
            break;
        default:
            printf("Invalid input");
        }
    } /* while loop */
while (menu != 4);
    return 0;
}

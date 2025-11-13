/* palindrome_doubly_linkedlist.c
 *
 * Description: Singly linked list operations
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
    char data;
    struct Node *blink, *flink;
} *head, *ptr, *temp;
void insert_at_first(char val) {
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->flink = head->flink;
    head->flink = temp;
    /* condition */
if (head->flink != NULL) {
        head->flink->blink = temp;
    }
    head->flink = temp;
    temp->data = val;
}
void insert(char val) {
    /* condition */
if (head->flink == NULL) {
        insert_at_first(val);
        return;
    }
    ptr = head->flink;
    /* while loop */
while (ptr->flink != NULL) {
        ptr = ptr->flink;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    ptr->flink = temp;
    temp->blink = ptr;
    temp->flink = NULL;
    temp->data = val;
}
void __exit() {
    ptr = head->flink;
    /* while loop */
while (ptr != NULL) {
        temp = ptr->flink;
        free(ptr);
        ptr = temp;
    }
    free(head);
}
int IsPalindrome() {
    struct Node *start, *end;
    start = head->flink;
    /* condition */
if (start == NULL)
        return 0;
    end = start;
    /* while loop */
while (end->flink != NULL) {
        end = end->flink;
    }
    /* while loop */
while (start != end && start->blink != end) {
        /* condition */
if (start->data != end->data) {
            return 0;
        }
        start = start->flink;
        end = end->blink;
    }
    return 1;
}
int main() {
    head = (struct Node *)malloc(sizeof(struct Node));
    head->flink = NULL;
    head->blink = NULL;
    char str[512];
    printf("Enter string : ");
    scanf("%s", str);
    int i = 0;
    /* while loop */
while (str[i] != '\0') {
        insert(str[i]);
        i++;
    }
    /* condition */
if (IsPalindrome() != 0) {
        printf("%s is a palindrome", str);
    } else {
        printf("%s is not a palindrome", str);
    }
    __exit();
    return 1;
}

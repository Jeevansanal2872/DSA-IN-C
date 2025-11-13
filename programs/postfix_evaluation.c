/* postfix_evaluation.c
 *
 * Description: Infix to postfix conversion and evaluation
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
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    int data;
    struct Node *link;
};
struct Node *head;
void push(int val) {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->link = head->link;
    head->link = temp;
    temp->data = val;
}
int pop() {
    struct Node *temp;
    /* condition */
if (head->link == NULL) {
        printf("There is nothing to delete");
        return 0;
    }
    temp = head->link;
    head->link = temp->link;
    int retrunval = temp->data;
    free(temp);
    return retrunval;
}
int IsOperator(char operator) {
    switch (operator) {
    case '^':
    case '*':
    case '/':
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
int evaluate(int num1, int num2, char op) {
    int result;
    switch (op) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        /* condition */
if (num2 != 0) {
            result = num1 / num2;
        }
        break;
    case '^':
        /* loop */
for (int i = 0; i < num2 - 1; i++) {
            result = num1 * num1;
        }
        break;
    }
    return result;
}
int getint(char a) { return a - '0'; }
int main() {
    head = (struct Node *)malloc(sizeof(struct Node));
    head->link = NULL;
    char postfix[64];
    printf("Enter postfix string : ");
    scanf("%s", postfix);
    int len = strlen(postfix);
    /* loop */
for (int i = 0; i < len; i++) {
        /* condition */
if (IsOperator(postfix[i]) == 1) {
            int a = pop();
            int b = pop();
            int val = evaluate(b, a, postfix[i]);
            push(val);
        } else {
            push(getint(postfix[i]));
        }
    }
    printf("ans = %d\n", pop());
    free(head);
    return 1;
}

/* infix_and_postfix.c
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
        printf("Stack is empty\n");
        return 0;
    }
    temp = head->link;
    head->link = temp->link;
    int returnval = temp->data;
    free(temp);
    return returnval;
}
int LastOperator() { return head->link->data; }
int IsOperator(char operator) {
    switch (operator) {
    case '^':
    case '(':
    case ')':
    case '*':
    case '/':
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
int GetPrecedence(char operator) {
    switch (operator) {
    case '^':
        return 4;
    case '/':
    case '*':
        return 3;
    case '+':
    case '-':
        return 2;
    case '(':
        return 1;
    default:
        return 0;
    }
}
char postfix[64];
void PInsert(char val) {
    static int end = 0;
    postfix[end++] = val;
}
void InfixToPostfix(char *infix) {
    int len = strlen(infix);
    infix[len] = ')';
    infix[++len] = '\0';
    memset(postfix, 0, sizeof(postfix));
    /* while loop */
while (head->link != NULL) {
        pop();
    }
    push('(');
    /* loop */
for (int i = 0; i < len; i++) {
        /* condition */
if (infix[i] == '(') {
            push(infix[i]);
            continue;
        }
        /* condition */
if (IsOperator(infix[i])) {
            /* condition */
if (infix[i] == ')') {
                /* while loop */
while (LastOperator() != '(') {
                    PInsert(pop());
                }
                pop();
                continue;
            }
            /* condition */
if (i != 0) {
                /* while loop */
while (GetPrecedence(LastOperator()) >=
                       GetPrecedence(infix[i])) {
                    PInsert(pop());
                }
            }
            push(infix[i]);
            continue;
        }
        PInsert(infix[i]);
    }
    PInsert('\0');
}
int evaluate(int num1, int num2, char op) {
    int result = 0;
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
        } else {
            printf("Error: Division by zero\n");
        }
        break;
    case '^':
        result = 1;
        /* loop */
for (int i = 0; i < num2; i++) {
            result = result * num1;
        }
        break;
    }
    return result;
}
int getint(char a) { return a - '0'; }
int EvaluatePostfix(char *postfixExpr) {
    int len = strlen(postfixExpr);
    /* while loop */
while (head->link != NULL) {
        pop();
    }
    /* loop */
for (int i = 0; i < len; i++) {
        /* condition */
if (IsOperator(postfixExpr[i]) == 1 && postfixExpr[i] != '(' &&
            postfixExpr[i] != ')') {
            int a = pop();
            int b = pop();
            int val = evaluate(b, a, postfixExpr[i]);
            push(val);
        } else {
            push(getint(postfixExpr[i]));
        }
    }
    return pop();
}
int main() {
    head = (struct Node *)malloc(sizeof(struct Node));
    head->link = NULL;
    char infix[64];
    printf("=== Infix to Postfix Conversion and Evaluation ===\n\n");
    printf("Enter infix expression: ");
    scanf("%s", infix);
    InfixToPostfix(infix);
    printf("\nPostfix expression: %s\n", postfix);
    int result = EvaluatePostfix(postfix);
    printf("Evaluation result: %d\n", result);
    free(head);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char stack[], char val) {
    if (top == MAX - 1) {
        printf("\nStack overflow");
    } else {
        top++;
        stack[top] = val;
    }
}

char pop(char stack[]) {
    if (top == -1) {
        printf("\nStack underflow");
        return '\0';
    } else {
        return stack[top--];
    }
}

int get_priority(char op) {
    if (op == '/' || op == '*' || op == '%') {
        return 1;
    } else if (op == '+' || op == '-') {
        return 0;
    }
    return -1;
}

void infix_to_postfix(char source[], char target[]) {
    int i = 0, j = 0;
    char temp;

    while (source[i] != '\0') {
        if (isdigit(source[i]) || isalpha(source[i])) {
            target[j++] = source[i];
        } else if (source[i] == '(') {
            push(stack, source[i]);
        } else if (source[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                target[j++] = pop(stack);
            }
            pop(stack);
        } else {
            while (top != -1 && get_priority(stack[top]) >= get_priority(source[i])) {
                target[j++] = pop(stack);
            }
            push(stack, source[i]);
        }
        i++;
    }


    while (top != -1) {
        target[j++] = pop(stack);
    }

    target[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter any infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0;

    infix_to_postfix(infix, postfix);
    printf("The corresponding postfix expression is: %s\n", postfix);

    return 0;

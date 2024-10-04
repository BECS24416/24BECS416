#include <stdio.h>
#include <stdlib.h>
#define MAX 100


void push(int stack[], int *top);
void pop(int stack[], int *top);
void display(int stack[], int top);

int main() {
    int stack[MAX];
    int top = -1;
    int ch;

    do {
        printf("\nStack Operations Menu:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch); // Corrected input handling

        switch (ch) {
            case 1:
                push(stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (1);

    return 0;
}

void push(int stack[], int *top) {
    if (*top >= MAX - 1) {
        printf("Stack Overflow: Cannot push to a full stack.\n");
    } else {
        int element;
        printf("Enter element to push: ");
        scanf("%d", &element);
        (*top)++;
        stack[*top] = element;
        printf("Element %d pushed at position %d.\n", element, *top);
    }
}

void pop(int stack[], int *top) {
    if (*top < 0) {
        printf("Stack Underflow: Cannot pop from an empty stack.\n");
    } else {
        printf("Element %d popped from position %d.\n", stack[*top], *top);
        (*top)--;
    }
}

void display(int stack[], int top) {
    if (top < 0) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements (from top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

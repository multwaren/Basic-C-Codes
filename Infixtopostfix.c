#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return (s->top == -1);
}

bool isFull(Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}

void infixToPostfix(char *expression, char *result) {
    Stack stack;
    initialize(&stack);

    int i, j;
    char ch;

    for (i = 0, j = 0; expression[i] != '\0'; i++) {
        ch = expression[i];

        if (isalnum(ch)) {
            result[j++] = ch;
        }
        else if (ch == '(') {
            push(&stack, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                result[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) != '(') {
                printf("Invalid expression\n");
                return;
            }
            else {
                pop(&stack); // Pop '(' from the stack
            }
        }
        else if (isOperator(ch)) {
            while (!isEmpty(&stack) && precedence(ch) <= precedence(peek(&stack))) {
                result[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(&stack)) {
        result[j++] = pop(&stack);
    }

    result[j] = '\0'; // Add null terminator to the result string
}

int main() {
    char infix[MAX_SIZE];
    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    char postfix[MAX_SIZE];
    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}


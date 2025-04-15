#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
} *top = NULL;

// Push operation
void push(char x) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("Stack is full\n");
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// Pop operation
char pop() {
    struct Node *t;
    char x = -1;

    if (top == NULL)
        printf("Stack is Empty\n");
    else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

// Display the stack (for debugging)
void Display() {
    struct Node *p = top;
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Check if expression has balanced parentheses
int isBalanced(char *exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')') {
            if (top == NULL)
                return 0;
            pop();
        }
    }
    return (top == NULL);
}

// Precedence of operators
int pre(char x) {
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

// Check if character is operand
int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

// Infix to Postfix conversion
char *InToPost(char *infix) {
    int i = 0, j = 0;
    int len = strlen(infix);
    char *postfix = (char *)malloc((len + 2) * sizeof(char));

    while (infix[i] != '\0') {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            while (top != NULL && pre(infix[i]) <= pre(top->data))
                postfix[j++] = pop();
            push(infix[i++]);
        }
    }
    while (top != NULL)
        postfix[j++] = pop();

    postfix[j] = '\0';
    return postfix;
}

// Main function
int main() {
    const char *infix = "a+b*c-d/e";
    push('#');  // Sentinel value to avoid null pointer

    char *postfix = InToPost((char*)infix);

    printf("Postfix: %s\n", postfix);

    return 0;
}

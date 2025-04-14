// Stack using Linked List C
#include <stdio.h>
#include <stdlib.h>

// Node structure for the stack
struct Node {
    int data;
    struct Node *next;
} *top = NULL;

// Push operation
void push(int x) {
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
int pop() {
    struct Node *t;
    int x = -1;

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

// Display the stack
void Display() {
    struct Node *p = top;

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Main function
int main() {
    push(10);
    push(20);
    push(30);

    Display();

    printf("Popped element: %d\n", pop());

    Display();

    return 0;
}

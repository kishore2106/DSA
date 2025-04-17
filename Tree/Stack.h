// Stack Header for Binary Tree

#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    struct Node **S;
};

void createStack(struct Stack *st, int size){
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size*sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *x){
    if(st->top != st->size - 1){
        st->top++;
        st->S[st->top]=x;
    }
}

Node* pop(struct Stack *st){
    Node *x=NULL;
    if(st->top!=-1){
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int isEmpty(struct Stack *st){
    return st->top==-1;
}

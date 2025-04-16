#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue{
    int size;
    int front;
    int rear;
    Node **Q; // pointer of type node
};

// Create a new queue
void create(struct  Queue *q, int size){
    q->size=size;
    q->Q=(Node **)malloc(q->size*sizeof(Node *)); // Array of pointers
    q->front=q->rear=-1;
}

// Inserting element to Queue (Enqueue)
void enqueue(struct Queue *q, Node * x){
    if(q->rear==q->size-1){
        printf("Queue is full");
    } else {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

// Deleting element from Queue (Dequeue)
Node * dequeue(struct Queue *q){
    Node * x=NULL;
    if(q->front==q->rear){
        printf("Queue is empty");
    } else {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q){
    return q.front==q.rear;
}
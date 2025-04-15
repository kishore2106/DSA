// Queue Impl using C

#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

// Create a new queue
void create(struct  Queue *q, int size){
    q->size=size;
    q->Q=(int *)malloc(q->size*sizeof(int));
    q->front=q->rear=-1;
}

// Inserting element to Queue (Enqueue)
void enqueue(struct Queue *q, int x){
    if(q->rear==q->size-1){
        printf("Queue is full");
    } else {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int main(){

    struct Queue q;
    create(&q, 5);

    return 0;
}
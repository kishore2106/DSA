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

int main(){

    struct Queue q;
    create(&q, 5);

    return 0;
}
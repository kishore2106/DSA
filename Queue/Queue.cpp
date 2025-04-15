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

// Deleting element from Queue (Dequeue)
int dequeue(struct Queue *q){
    int x=-1;
    if(q->front==q->rear){
        printf("Queue is empty");
    } else {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

// Display elements of Queue
void display(struct Queue *q){
    int x=-1;
    for(int i=q->front+1; i<=q->rear; i++){
        x = q->Q[i];
        printf("%d ",x);
    }
    printf("\n");
}

int main(){

    struct Queue q;
    create(&q, 5);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    display(&q);

    dequeue(&q);

    display(&q);

    return 0;
}
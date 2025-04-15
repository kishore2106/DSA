// Queue Impl using Linked List
# include<stdio.h>
# include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*front=NULL, *rear=NULL;

void enqueue(int x){
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Queueu is Full\n");
    } else {
        t->data=x;
        t->next=NULL;
        if(front==NULL){
            front=rear=t;
        } else {
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue(){
    int x=-1;
    struct Node *p;
    if(front==NULL){
        printf("Queue is Empty\n");
    } else {
        p=front;
        front=front->next;
        x=p->data;
        free(p);
    }
    return x;
}

void display(){
    struct Node *p=front;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    enqueue(1);
    enqueue(3);
    enqueue(5);
    enqueue(7);
    enqueue(9);
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}
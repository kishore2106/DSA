// Queue Impl using C++
#include <iostream>
#include <stdio.h>
using namespace std;

class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class Queue{
    public:
        int size;
        int front;
        int rear;
        Node **Q;
        Queue();
        Queue(int size);
        ~Queue();
        void enqueue(Node* x);
        Node* dequeue();
        void display();
        int isEmpty();
};

int Queue::isEmpty(){
    return front==rear;
}

Queue::Queue(){
    size = 10;
    front = rear = -1;
    Q = new Node*[size];
}

Queue::Queue(int size){
    this->size = size;
    front = rear = -1;
    Q = new Node*[this->size];
}

Queue::~Queue(){
    delete[] Q;
}

void Queue::enqueue(Node* x){
    if(rear == size - 1){
        cout<<"Queue is full";
    } else {
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::dequeue(){
    Node* x=NULL;
    if(front==rear){
        cout<<"Queue is empty";
    } else {
        front++;
        x=Q[front];
    }
    return x;
}
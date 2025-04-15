// Queue Impl using C++
#include <iostream>
using namespace std;

class Queue{
    public:
        int size;
        int front;
        int rear;
        int *Q;
        Queue();
        Queue(int size);
        ~Queue();
        void enqueue(int x);
        int dequeue();
        void display();
};

Queue::Queue(){
    size = 10;
    front = rear = -1;
    Q = new int[size];
}

Queue::Queue(int size){
    this->size = size;
    front = rear = -1;
    Q = new int[this->size];
}

Queue::~Queue(){
    delete[] Q;
}

void Queue::enqueue(int x){
    if(rear == size - 1){
        cout<<"Queue is full";
    } else {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue(){
    int x=-1;
    if(front==rear){
        cout<<"Queue is empty";
    } else {
        front++;
        x=Q[front];
    }
    return x;
}

void Queue::display(){
    int i;
    for(i=front+1; i<=rear; i++){
        cout<<Q[i]<<" ";
    }
    cout<<"\n";
}

int main(){

    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    

    return 0;
}
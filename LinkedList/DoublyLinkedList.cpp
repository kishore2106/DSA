// Doubly Linked List
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}*first=NULL;

// Create Doubly Linked List
void create(int a[], int n){
    struct Node *p,*t;
    first=new Node;
    first->data=a[0];
    first->prev=NULL;
    first->next=NULL;
    p=first;

    for(int i=1; i<n; i++){
        t=new Node;
        t->data=a[i];
        t->prev=p;
        t->next=NULL;
        p->next=t;
        p=t;
    }
}

// Length of Doubly Linked List
int Length(struct Node *p){
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

int main(){
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    create(a, 10);
    cout<<Length(first);
    return 0;
}
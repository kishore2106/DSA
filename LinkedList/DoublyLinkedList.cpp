// Doubly Linked List
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}*first=NULL;

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
        p=t;
    }

}

int main(){
    int a[] = {10, 20, 30, 40, 50};
    create(a, 5);

    return 0;
}
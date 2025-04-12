#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
}*Head;

void Create(int a[], int n){
    int i;
    struct Node *t;
    t=new Node;
    t->data=a[0];
    t->next=Head;
    Head=t;

    for(i=1; i<n; i++){
        t=new Node;
        t->data=a[i];
        Head->next=t;
        t->next=Head;
    }
}

int main(){
    int a[] = {1, 2, 3, 4, 5};
    Create(a, 5);

    return 0;
}
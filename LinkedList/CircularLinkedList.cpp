#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
}*Head;

// Create Circular Linked List
void Create(int a[], int n){
    int i;
    struct Node *t,*last;
    Head=new Node;
    Head->data=a[0];
    Head->next=Head;
    last=Head;

    for(i=1; i<n; i++){
        t=new Node;
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

// Display Circular LL
void Display(struct Node *h){
    do{
        cout<<h->data<<" ";
        h=h->next;
    } while(h!=Head);
    cout<<endl;
}

int main(){
    int a[] = {1, 2, 3, 4, 5};
    Create(a, 5);

    Display(Head);
    return 0;
}
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

// Display Circular LL using recursion
void RDisplay(struct Node *h){
    static int flag=0;
    if(h!=Head || flag==0){
        flag=1;
        cout<<h->data<<" ";
        RDisplay(h->next);
    }
    flag=0;
}

// Length of Circular LL
int Length(struct Node *h){
    int count=0;
    do{
        count++;
        h=h->next;
    } while(h!=Head);
    return count;
}

// Insert Node in Circular LL
void Insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;
    if(index<0 || index>=Length(p)){
        return;
    }
    if(index == 0){
        t=new Node;
        t->data=x;
        if(Head==NULL){
            Head=t;
            Head->next=Head;
        } else{
            while(p->next!=Head) p=p->next;
            p->next=t;
            t->next=Head;
            Head=t;
        }
    } else {
        for(i=0; i<index-1; i++) p=p->next;
        t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}

// Delete node at given index
int Delete(struct Node *p, int index) {
    struct Node *q;
    int i, x;

    if (index < 1 || index > Length(Head))
        return -1;

    if (index == 1) {
        while (p->next != Head)
            p = p->next;
        x = Head->data;
        if (Head == p) {
            delete Head;
            Head = NULL;
        } else {
            p->next = Head->next;
            delete Head;
            Head = p->next;
        }
    } else {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

int main(){
    int a[] = {1, 2, 3, 4, 5};
    Create(a, 5);

    // cout<<Length(Head)<<endl;
    // Display(Head);
    RDisplay(Head);
    cout<<endl;
    // Insert(Head, 2, 10);
    cout<<Delete(Head,1)<<endl;
    RDisplay(Head);
    return 0;
}
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

// Display Doubly Linked List
void Display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

// Inserting Node in a DLL
void Insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;
    if(index<0 || index>Length(p)) return;
    if(index==0){
        t=new Node;
        t->data=x;
        t->next=first;
        t->prev=NULL;
        first->prev=t;
        first=t;
    } else {
        t=new Node;
        t->data=x;
        for(i=0;i<index-1;i++) p=p->next;
        t->next=p->next;
        t->prev=p;
        if(p->next) p->next->prev=t;
        p->next=t;
    }
}

// Delete Node in DLL
int Delete(struct Node *p, int index){
    struct Node *t;
    int x=-1;
    if(index<1 || index>Length(p)){
        return -1;
    }
    if(index==1){
        first=first->next;
        if(first->next) first->prev=NULL;
        x=p->data;
        delete p;
    } else {
        for(int i=0;i<index-1;i++) p=p->next;
        p->prev->next=p->next;
        if(p->next) p->next->prev=p->prev;
        x=p->data;
        delete p;
    }
    return x;
}

// Reverse a DDL
void Reverse(struct Node *p){
    struct Node *t;
    while(p!=NULL){
        t=p->next;
        p->next=p->prev;
        p->prev=t;
        p=p->prev;
        if(p!=NULL && p->next==NULL){
            first=p;
        }
    }
}

int main(){
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    create(a, 10);
    // cout<<Length(first)<<endl;
    Display(first);
    // Insert(first, 10, 45);
    // cout<<Delete(first,4)<<endl;
    Reverse(first);
    Display(first);
    return 0;
}
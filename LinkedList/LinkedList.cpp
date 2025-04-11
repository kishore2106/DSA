// Linked List

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first;

// Creating LL using Array
void create(int A[], int n){
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++){
        t = new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

// printing elements of LL
void Display(struct Node *p){
    while(p != NULL){
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}

// printing elements of LL using recursion
void RDisplay(struct Node *p){
    if(p != NULL){
        cout<<p->data<<"->";
        RDisplay(p->next);
    } else {
        cout<<"NULL";
    }
    
}

// printing reverse of LL using recursion
void RevDisplay(struct Node *p){
    if( p != NULL ){
        RevDisplay(p->next);
        cout<<p->data<<" ";
    } 
    
}

// Counting elements of LL
int Count(struct Node *p){
    int count = 0;
    while(p!=0){
        count++;
        p=p->next;
    }
    return count;
}

// Counting elements of LL using recursion
int RCount(struct Node *p){
    if(p!=NULL){
        return 1 + RCount(p->next);
    } else {
        return 0;
    }
}

// Sum of elements of LL
int Sum(struct Node *p){
    int sum = 0;
    while(p!=NULL){
        sum += p->data;
        p=p->next;
    }
    return sum;
}

// Sum of elements of LL using recursion
int RSum(struct Node *p){
    if(p!=NULL){
        return RSum(p->next)+p->data;
    } else {
        return 0;
    }
}

// Max element of LL
int Max(struct Node *p){
    int max = INT_MIN;
    while(p!=NULL){
        if(p->data > max){
            max = p->data;
        }
        p=p->next;
    }
    return max;
}

// Max element of LL using recursion
int RMax(struct Node *p){
    int x=0;
    if(p==0) return INT_MIN;
    x=RMax(p->next);
    if(x>p->data){
        return x;
    } else {
        return p->data;
    }
}

// Min element of LL
int Min(struct Node *p){
    int min = INT_MAX;
    while(p!=NULL){
        if(p->data < min){
            min = p->data;
        }
        p=p->next;
    }
    return min;
}

// Min element of LL using recursion
int RMin(struct Node *p){
    int x=0;
    if(p==0) return INT_MAX;
    x=RMin(p->next);
    if(p->data<x){
        return p->data;
    } else {
        return x;
    }
}

int main(){
    int A[] = {28,5,7,30,15,17};
    create(A, 6);

    // RevDisplay(first);
    // cout<<Count(first);
    // cout<<RCount(first);
    // cout<<Sum(first);
    // cout<<RSum(first);
    // cout<<Max(first);
    // cout<<RMax(first);
    // cout<<Min(first);
    cout<<RMin(first);

    return 0;
}
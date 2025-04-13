// Linked List

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first, *second, *third;

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

// Create second LL
void create2(int A[], int n){
    int i;
    struct Node *t, *last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

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

// Linear Search in LL
struct Node* Search(struct Node *p, int key){
    while(p!=NULL){
        if(p->data == key){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

// Linear Search in LL using recursion
struct Node* RSearch(struct Node *p, int key){
    if(p==0) return NULL;
    if(key==p->data)
        return p;
    return RSearch(p->next, key);
}

// Linear Search in LL and Move to head
struct Node* HSearch(struct Node *p, int key){
    struct Node* q;
    while(p!=NULL){
        if(p->data == key){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

// Insert Node in LL
void Insert(struct Node *p, int index, int x){
    struct Node *t;
    if(index < 0 || index > Count(p)){
        return;
    }
    t=new Node;
    t->data=x;

    if(index == 0){
        t->next=first;
        first=t;
    } else {
        for(int i=0; i<index-1; i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
} 

// Insert Node in sorted LL
void InsertSorted(struct Node *p, int x){
    struct Node *t, *q=NULL;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if(first==NULL){
        first=t;
    } else {
        while(p && p->data < x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        } else {
            t->next=q->next;
            q->next=t;
        }
    }   
}

// Delete a Node from a given position in LL
int Delete(struct Node *p, int index){
    struct Node *q;
    int x=-1, i;

    if(index < 1 || index > Count(p)){
        return x;
    }
    if(index == 1){
        x = first->data;
        q = first;
        first = first->next;
        delete q;
        return x;
    } else {
        for(i=0; i<index-1; i++){
            q=p;
            p=p->next;
        }
        x=p->data;
        q->next=p->next;
        delete p;
        return x;
    }
}

// Check the given list is sorted or not
int IsSorted(struct Node *p){
    int x=INT_MIN;
    while(p!=NULL){
        if(p->data < x){
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}

// Remove Duplicate node from a sorted LL
void RemoveSortDup(struct Node *p){
    struct Node *q = p->next;
    while(q != NULL){
        if(p->data != q->data){
            p=q;
            q=q->next;
        } else {
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}

// Reversing a LL by copying elements using Array
void ReverseArray(struct Node *p){
    struct Node *q=p;
    int i;
    int *a = new int[Count(p)];
    while(q!=NULL){
        a[i++]=q->data;
        q=q->next;
    }
    q=first; i--;
    while(q!=NULL){
        q->data=a[i--];
        q=q->next;
    }

}

// Reversing a LL using sliding pointer technique
void ReverseSlide(struct Node *p){
    struct Node *q = NULL, *r = NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

// Reversing a LL using Recursion
void ReverseRec(struct Node *q, struct Node *p){
    if(p){
        ReverseRec(p, p->next);
        p->next=q;
    } else {
        first=q;
    }
}

// Concate 2 LL
void Concatenate(struct Node *p, struct Node *q){
    third=p;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
}

// Merging 2 sorted LL
void Merge(struct Node *p, struct Node *q){
    struct Node *last=NULL;
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    } else {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }

    while(p && q){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        } else {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }

    if(p) last->next=p;
    else last->next=q;
}

// Check the LL is Loop or Linear
int CheckLoop(struct Node *f){
    struct Node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    } while(p && q && p!=q);
    if(p==q){
        return 1;
    } else {
        return 0;
    }
}

// Middle Node in LL using 2 pointers
int Middle(struct Node *p){
    struct Node *q;
    q=p;
    while(q!=NULL && q->next!=NULL){
        q=q->next;
        if(q) q=q->next;
        if(p) p=p->next;
    }
    return p->data;
}

int main(){
    int A[] = {10,20,30,40,50};
    int B[] = {5,15,25,35,45};
    create(A, 5);
    create2(B, 5);

    // RevDisplay(first);
    // cout<<Count(first);
    // cout<<RCount(first);
    // cout<<Sum(first);
    // cout<<RSum(first);
    // cout<<Max(first);
    // cout<<RMax(first);
    // cout<<Min(first);
    // cout<<RMin(first);
    // cout<<RMin(first);

    // struct Node* temp = Search(first, 1);
    // struct Node* temp = RSearch(first, 30);
    // Display(first);
    // struct Node* temp = HSearch(first, 30);
    // if(temp!=NULL){
    //     cout<<"Element found"<<endl;
    // } else {
    //     cout<<"Element not found"<<endl;
    // }
    // Display(first);
    // Insert(first, 0, 10);
    // Insert(first, 3, 20);
    // InsertSorted(first,35);
    // InsertSorted(first,55);
    // InsertSorted(first,5);
    // cout<<Delete(first,6)<<endl;
    // cout<<IsSorted(first);
    // RemoveSortDup(first);
    // ReverseArray(first);
    // ReverseSlide(first);
    // ReverseRec(NULL, first);
    // Concatenate(first,second);
    // Display(first);
    // Display(second);
    // Merge(first, second);

    // struct Node *t1, *t2;
    // t1 = first->next->next;
    // t2 = first->next->next->next->next;
    // t2->next=t1;

    // if(CheckLoop(first)){
    //     cout<<"Loop found"<<endl;
    // } else {
    //     cout<<"Linear LL"<<endl;
    // }
    Display(first);
    cout<<Middle(first);

    return 0;
}
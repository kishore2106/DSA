// AVL(Adelson-Velsky Levndis) Tree Impl in C
#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* lchild;
    int data;
    int height;
    struct Node* rchild;
}*root=NULL;

// Node Height of AVL Tree
int NodeHeight(struct Node *p){
    int hl, hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}

// Balance Factor of AVL Tree
int BalanceFactor(struct Node *p){
    int hl, hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;

    return hl-hr;
}

// Inserting a node in AVL Tree
struct Node* RInsert(struct Node* p, int key){
    struct Node *t;
    if(p==NULL){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->height=1;
        t->lchild=t->rchild=t->height=0;
        return t;
    }
    if(key<p->data){
        p->lchild=RInsert(p->lchild,key);
    } else if(key>p->data){
        p->rchild=RInsert(p->rchild,key);
    }
    p->height=NodeHeight(p);
    return p;
}

int main(){


    return 0;
}
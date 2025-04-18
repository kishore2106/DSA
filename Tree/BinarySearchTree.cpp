// Binary Search Tree using C

#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *lchild;
    struct Node *rchild;
    int data;
}*root=NULL;

// Inserting a node in the binary search tree
void Insert(int key){
    struct Node *t=root;
    struct Node *p, *r;
    if(root==NULL){
        p=(struct Node*)malloc(sizeof(struct Node*));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL){
        r=t;
        if(key<t->data){
            t=t->lchild;
        } else if(key>t->data){
            t=t->rchild;
        } else{
            return;
        }
    }
    p=(struct Node*)malloc(sizeof(struct Node*));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data) r->lchild=p;
    else r->rchild=p;


}

int main(){

    return 0;
}
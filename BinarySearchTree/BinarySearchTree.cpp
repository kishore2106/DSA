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

// Inorder traversal of the binary search tree
void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

// Search element in Binary Search Tree
Node* Search(int key){
    struct Node *t=root;
    while(t!=NULL){
        if(key<t->data){
            t=t->lchild;
        } else if(key>t->data){
            t=t->rchild;
        } else{
            return t;
        }
    }
    return NULL;
}

int main(){
    Insert(50);
    Insert(30);
    Insert(20);
    Insert(40);
    Insert(70);
    Insert(60);
    Insert(80);
    Inorder(root);
    printf("\n");
    struct Node *res=Search(30);
    if(res!=NULL){
        printf("Key Found");
    } else {
        printf("Key Not Found");
    }
    res=Search(38);
    printf("\n");
    if(res!=NULL){
        printf("Key Found");
    } else {
        printf("Key Not Found");
    }


    return 0;
}
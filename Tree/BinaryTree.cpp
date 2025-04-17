// Binary Tree using Queue in C

#include<stdio.h>
// #include<Queue.h>
#include "Queue.h"
#include "Stack.h"

struct Node * root=NULL;

void createTree(){
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q,100);

    printf("Enter root value ");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q)){
        p=dequeue(&q);
        printf("Enter left child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("Enter right child %d ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}

void preorder(struct Node *p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p){
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void postorder(struct Node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

// Iterative version Tree Traversal
void IPreorderIter(struct Node *t){
    struct Stack st;
    createStack(&st, 100);
    while(t!=NULL || !isEmpty(&st)){
        if(t!=NULL){
            printf("%d ",t->data);
            push(&st, t);
            t=t->lchild;
        } else {
            t=pop(&st);
            t=t->rchild;
        }
    }
}

int main(){

    createTree();

    IPreorderIter(root);
    printf("\n");
    // inorder(root);
    // printf("\n");
    // postorder(root);
    return 0;
}
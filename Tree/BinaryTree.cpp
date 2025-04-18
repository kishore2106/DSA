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

// Iteravtice Inorder Traversal using Stack
void InorderIter(struct Node *t){
    struct Stack st;
    createStack(&st, 100);
    while(t!=NULL || !isEmpty(&st)){
        if(t!=NULL){
            push(&st, t);
            t=t->lchild;
        } else {
            t=pop(&st);
            printf("%d ",t->data);
            t=t->rchild;
        }
    }
}

// Iteravtice Postorder Traversal using Stack
void PostorderIter(struct Node *t){
    struct Stack st;
    createStack(&st, 100);
    intptr_t temp;
    while(t!=NULL || !isEmpty(&st)){
        if(t!=NULL){
            push(&st, t);
            t=t->lchild;
        } else {
            temp=(intptr_t)pop(&st);
            if (temp > 0) {
                push(&st, (Node *)(-temp));
                t = ((Node *)temp)->rchild;
            } else {
                printf("%d ", ((Node *)(-temp))->data);
                t = NULL;
            }
        }
    }
}

// Level Order Tree Traversal
void LevelOrder(struct Node *root){
    struct Queue q;
    create(&q, 100);
    printf("%d ",root->data);
    enqueue(&q,root);
    while(!isEmpty(q)){
        root=dequeue(&q);
        if(root->lchild){
            printf("%d ",root->lchild->data);
            enqueue(&q,root->lchild);
        } 
        if(root->rchild) {
            printf("%d ",root->rchild->data);
            enqueue(&q,root->rchild);
        }
    }

}

// Counting Number of Nodes in a Binary Tree
int count(struct Node * root){
    int x, y;
    if(root!=NULL){
        x = count(root->lchild);
        y = count(root->rchild);
        return x + y + 1;
    }
    return 0;
}

// Height of binary tree
int height(struct Node* root){
    int x=0, y=0;
    if(root==0){
        return 0;
    }
    x = height(root->lchild);
    y = height(root->rchild);
    if(x>y){
        return x+1;
    } else {
        return y+1;
    }
}

int main(){

    createTree();

    IPreorderIter(root);
    printf("\n");
    InorderIter(root);
    printf("\n");
    PostorderIter(root);
    printf("\n");
    LevelOrder(root);

    printf("\nNumber of Nodes %d",count(root));
    printf("\nHeight of a Binary Tree %d",height(root));
    return 0;
}
// Binary Tree using Queue in C++

#include<iostream>
#include "QueueC++.h"
using namespace std;

class Tree{
    public:
        Node *root;
        Tree(){root=NULL;};
        void CreateTree();
        void Preorder(Node *p);
        void Postorder(Node *p);
        void Inorder(Node *p);
        void LevelOrder(Node *p);
        void Height(Node *p);
};

void Tree::CreateTree(){
    Node *p, *t;
    int x;
    Queue q(100);

    printf("Enter root value ");
    scanf("%d",&x);
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);

    while(!q.isEmpty()){
        p=q.dequeue();
        printf("Enter left child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        printf("Enter right child %d ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p){
    if(p){
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

void Postorder(Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}

int main(){

    return 0;
}
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

// Recursively inserting a node in the binary search tree
Node* RInsert(struct Node *p, int key){
    struct Node *t = NULL;

    if (p == NULL){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;  // Return the new node
    }

    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);
    // If key == p->data, do nothing (no duplicates)

    return p;  // Return the original root pointer
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

// Recursive Binary Search function
Node* RSearch(struct Node *p, int key){
    if(p==NULL) return NULL;
    if(p->data==key){
        return p;
    } else if(key<p->data){
        return RSearch(p->lchild, key);
    } else{
        return RSearch(p->rchild, key);
    }
}

// Height of BinaryTree
int Height(Node *p) {
    int x;
    int y;
    if (p == NULL){
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

// InPredecessor for a Node
Node* InPre(Node *p) {
    while (p && p->rchild != NULL){
        p = p->rchild;
    }
    return p;
}

// InSuccessor for a Node
Node* InSucce(Node *p) {
    while (p && p->lchild != NULL){
        p = p->lchild;
    }
    return p;
}

int main(){
    // Insert(50);
    // Insert(30);
    // Insert(20);
    // Insert(40);
    // Insert(70);
    // Insert(60);
    // Insert(80);
    root = RInsert(root,50);
    RInsert(root,30);
    RInsert(root,20);
    RInsert(root,40);
    RInsert(root,70);
    RInsert(root,60);
    RInsert(root,80);
    Inorder(root);
    printf("\n");
    // root=Delete(root, 20);
    Inorder(root);
    printf("\n");
    // struct Node *res=Search(30);
    // struct Node *res=RSearch(root,30);
    // if(res!=NULL){
    //     printf("Key Found");
    // } else {
    //     printf("Key Not Found");
    // }
    // // res=Search(38);
    // res=RSearch(root,48);
    // printf("\n");
    // if(res!=NULL){
    //     printf("Key Found");
    // } else {
    //     printf("Key Not Found");
    // }


    return 0;
}
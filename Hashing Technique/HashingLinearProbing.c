#include<stdio.h>
#define SIZE 10

int hash( int key){
    return key%SIZE;
}

int probe(int H[], int key){
    int index=hash(key);
    int i=0;
    while((H[key+i])%SIZE!=0){
        i++;
    }
    return (index+i)%SIZE;
    
}

void Insert(int H[], int key){
    int index=hash(key);
    if(H[index]!=0){
        index = probe(H, key);
    }
    H[index]=key;

}

// Search element using Linear Probing
int Search(int H[], int key){
    int index=hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=key)
        i++;
    return (index+i)%SIZE;
}

int main(){
    int H[10]={0};
    Insert(H, 12);
    Insert(H, 25);
    Insert(H, 35);
    Insert(H, 26);
    int index=Search(H, 35);
    printf("Element %d found at index %d", H[index], index);

    return 0;
}
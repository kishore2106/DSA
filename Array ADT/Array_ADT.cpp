// Array ADT and its operations

#include<iostream>
using namespace std;

// properties
struct Array{
    int A[20];
    int size;
    int length;
};

// Display
void display(struct Array arr){
    cout<<"Elements are: ";
    for(int i=0; i<arr.length; i++) {
        cout<<arr.A[i]<<" ";
    }
}

// Append
void append(struct Array *arr, int x){
    if(arr->length < arr->size){
        arr->A[arr->length++] = x;
    }

}

int main(){
    struct Array arr={{2,3,4,5,6},20,5};
    int i, n;
    append(&arr, 7);
    display(arr);
    
    return 0;
}
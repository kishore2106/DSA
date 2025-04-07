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

int main(){
    struct Array arr={{2,3,4,5,6},20,5};
    int i, n;

    display(arr);

    return 0;
}
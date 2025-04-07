// Demo Array ADT

#include<iostream>
using namespace std;

struct Array{
    // int *A;
    int A[20];
    int size;
    int length;
};

void display(struct Array arr){
    cout<<"Elements are: ";
    for(int i=0; i<arr.length; i++) {
        cout<<arr.A[i]<<" ";
    }
}

int main(){
    struct Array arr={{2,3,4,5,6},20,5};
    int i, n;
    // cout<<"Enter the size of array: ";
    // cin>>arr.size;
    // arr.A = new int[arr.size];
    // arr.length = 0;

    // cout<<"Enter number of numbers: ";
    // cin>>n;

    // cout<<"Enter the elements of array\n";
    // for(i=0; i<n; i++){
    //     cin>>arr.A[i];
    // }
    // arr.length = n;

    display(arr);

    return 0;
}
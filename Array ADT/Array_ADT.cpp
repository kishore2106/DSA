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

// Insert
void insert(struct Array *arr, int index, int x) {
    int i;
    if(index>=0 && index <= arr->length){
        for(i=arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1]; 
        }
        arr->A[index] = x;
        arr->length++;
    }
}

// Delete
int Delete(struct Array *arr, int index) {
    int x = 0;
    if(index >= 0 && index <= arr->length){
        x = arr->A[index];
        for(int i=index; i<arr->length-1; i++) {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }

    return 0;
}

// Swap
void Swap(int *i, int *j) {
    int temp;
    temp = *i;
    *i = *j;
    *j = temp; 
}

// Linear Search
int LinearSearch(struct Array *arr, int key){
    int i;
    for(i=0; i<arr->length; i++){
        if(key == arr->A[i]){
            // Transposition
            // Swap(&arr->A[i], &arr->A[i-1]);

            // Move to Front/Head
            Swap(&arr->A[0], &arr->A[i]);
            return i;
        }
    }
    return -1;
}

// Binary Search using Loop
int BinarySearch(struct Array arr, int key){
    int l, mid, h;
    l = 0;
    h = arr.length - 1;

    while(l <= h) {
        mid = (l + h)/2;
        if(key == arr.A[mid]) {
            return mid;
        } else if (key < arr.A[mid]) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

// Binary Search using Recursion
int RBinarySearch(struct Array arr, int l, int h, int key) {
    int mid;

    if(l <= h) {
        mid = (l+h)/2;
        if(key == arr.A[mid]){
            return mid;
        } else if(key < arr.A[mid]) {
            return RBinarySearch(arr, l, mid-1, key);
        } else {
            return RBinarySearch(arr, mid+1, h, key);
        }
    }
    return -1;
}

int main(){
    struct Array arr={{2,3,4,5,6},20,5};
    // int i, n;
    // append(&arr, 7);
    // insert(&arr, 2, 9);
    // cout<<Delete(&arr, 1)<<endl;
    // display(arr);
    // cout<<LinearSearch(&arr, 4)<<endl;
    // cout<<BinarySearch(arr, 8)<<endl;
    cout<<RBinarySearch(arr, 0, arr.length, 4)<<endl;

    display(arr);

    return 0;
}
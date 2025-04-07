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

// Get
int Get(struct Array arr, int index) {
    if(index >= 0 && index < arr.length) {
        return arr.A[index];
    }
    return -1;
}

// Set
void Set(struct Array *arr, int index, int x) {
    if(index >= 0 && index < arr->length) {
        arr->A[index] = x;
    }
}

// Max
int Max(struct Array arr) {
    int max = arr.A[0];
    int i;
    for (i=1; i<arr.length; i++) {
        if(arr.A[i] > max){
            max = arr.A[i];
        }     
    }
    return max;
}

// Min
int Min(struct Array arr) {
    int min = arr.A[0];
    int i;
    for (i=1; i<arr.length; i++) {
        if(arr.A[i] < min){
            min = arr.A[i];
        }     
    }
    return min;
}

// Sum
int Sum(struct Array arr) {
    int sum = 0;
    int i;
    for (i=0; i<arr.length; i++){
        sum = sum + arr.A[i];
    }
    return sum;
}

// Average
float Average(struct Array arr) {
    return (float)Sum(arr)/arr.length;
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

// Reversing Array using Auxilary Array
void Reverse(struct Array *arr) {
    int *B;
    int i, j;

    B = new int[arr->length];
    for(i=arr->length-1, j=0; i>=0; i--,j++){
        B[j] = arr->A[i];
    }
    for(i=0; i<arr->length; i++){
        arr->A[i] = B[i];
    }
}

// Reversing Array using 2 Pointers
void Reverse2(struct Array *arr) {
    int i, j, temp;
    for(i=0, j=arr->length-1; i<j; i++, j--) {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

// Left Shift
void LeftShit(struct Array *arr) {
    for(int i=1; i<arr->length; i++) {
        arr->A[i-1]=arr->A[i];
    }
    arr->A[arr->length-1] = 0;
}

// Right Shift
void RightShit(struct Array *arr) {
    for(int i=arr->length-1; i>0; i--) {
        arr->A[i]=arr->A[i-1];
    }
    arr->A[0] = 0;
}

// Left Rotate
void LeftRotate(struct Array *arr) {
    int temp = arr->A[0];
    for(int i=1; i<arr->length; i++) {
        arr->A[i-1]=arr->A[i];
    }
    arr->A[arr->length-1] = temp;
}

// Right Rotate
void RightRotate(struct Array *arr) {
    int temp = arr->A[arr->length-1];
    for(int i=arr->length-1; i>0; i--) {
        arr->A[i]=arr->A[i-1];
    }
    arr->A[0] = temp;
}

// Inserting an element into Sorted Array
void InsertSort(struct Array *arr, int x) {
    int i = arr->length-1;
    if (arr->length == arr->size) return;
    while(i>=0 && arr->A[i]>x){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

// Given Array is sorted or not
int isSorted(struct Array arr){
    int i;
    for(i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1])
        return 0;
    }
    return 1;
}

// Rearrage +ve and -ve
void Rearrange(struct Array *arr){
    int i,j;
    i=0;
    j=arr->length-1;
    
    while(i<j){
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j) Swap(&arr->A[i], &arr->A[j]);
    }
}

int main(){
    struct Array arr={{-2,-3,4,5,-6,10,-23,-15},20,8};
    // int i, n;
    // append(&arr, 7);
    // insert(&arr, 2, 9);
    // cout<<Delete(&arr, 1)<<endl;
    // display(arr);
    // cout<<LinearSearch(&arr, 4)<<endl;
    // cout<<BinarySearch(arr, 8)<<endl;
    // cout<<RBinarySearch(arr, 0, arr.length, 4)<<endl;
    // cout<<Get(arr, 3)<<endl;
    // Set(&arr, 3, 9);
    // cout<<Max(arr)<<" "<<Min(arr)<<endl;
    // cout<<Sum(arr)<<" "<<Average(arr)<<endl;
    // Reverse2(&arr);
    // LeftShit(&arr);
    // RightShit(&arr);
    // LeftRotate(&arr);
    // RightRotate(&arr);
    // InsertSort(&arr, 4);
    // cout<<isSorted(arr)<<endl;
    Rearrange(&arr);

    display(arr);

    return 0;
}
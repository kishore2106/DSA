// Array ADT and its operations

#include<iostream>
#include<stdio.h>
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

// Linear Search or Set Membership Operation
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

// Binary Search using Loop / Set Membership Operation
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

// Merging 2 sorted Array
struct Array* Merge(struct Array *arr1, struct Array *arr2) {
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length) {
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        } else {
            arr3->A[k++]=arr2->A[j++];
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i++];
    }
    for(;j<arr2->length;j++){
        arr3->A[k++]=arr2->A[j++];
    }
    arr3->length=arr1->length+arr2->length;
    arr3->size=arr1->size+arr2->size;
    return arr3;
}

// Set Operations
// Union of Sorted Array 
struct Array* Union(struct Array *arr1, struct Array *arr2) {
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length) {
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        } else if(arr2->A[j]<arr1->A[i]) {
            arr3->A[k++]=arr2->A[j++];
        } else {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i++];
    }
    for(;j<arr2->length;j++){
        arr3->A[k++]=arr2->A[j++];
    }
    arr3->length=k;
    arr3->size=arr1->size+arr2->size;
    return arr3;
}

// Union of unsorted Array
struct Array* UnSortUnion(struct Array *arr1, struct Array *arr2) {
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));

    arr3->size=arr1->size+arr2->size;
    while(i<arr1->length){
        arr3->A[k++]=arr1->A[i++];
    }
    arr3->length=arr1->length;

    bool count = false;
    for(int j=0; j<arr2->length;j++){
        count = false;
        for(int i=0;i<arr1->length;i++){
            if(arr2->A[j] == arr1->A[i]){
                count = true;
            }
        }
        if(count == false) {
            arr3->A[arr3->length++] = arr2->A[j];
        }
    }
    return arr3;
}

// Intersection of Sorted Array 
struct Array* Intersection(struct Array *arr1, struct Array *arr2) {
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length) {
        if(arr1->A[i]<arr2->A[j]){
            i++;
        } else if(arr2->A[j]<arr1->A[i]) {
            j++;
        } else if(arr1->A[i] == arr2->A[j]) {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }

    arr3->length=k;
    arr3->size=arr1->size+arr2->size;
    return arr3;
}

// Intersection of Unsorted Array
struct Array* UnSortInter(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));

    arr3->size=arr1->size+arr2->size;
    arr3->length=0;
    bool count = false;
    for(int j=0; j<arr2->length;j++){
        count = false;
        for(int i=0;i<arr1->length;i++){
            if(arr2->A[j] == arr1->A[i]){
                count = true;
            }
        }
        if(count == true) {
            arr3->A[arr3->length++] = arr2->A[j];
        }
    }
    return arr3;
}

// Difference of Sorted Array 
struct Array* Difference(struct Array *arr1, struct Array *arr2) {
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length) {
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        } else if(arr2->A[j]<arr1->A[i]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i++];
    }

    arr3->length=k;
    arr3->size=arr1->size+arr2->size;
    return arr3;
}

// Difference of Un-Sorted Array
struct Array* UnSortDiff(struct Array *arr1, struct Array *arr2){
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    arr3->size = arr1->size + arr2->size;
    arr3->length = 0;
    bool count = false;
    for(int i=0; i<arr1->length; i++){
        count = false;
        for(int j=0; j<arr2->length; j++){
            if (arr1->A[i] == arr2->A[j]) {
                count = true;
            }
        }
        if(count == false) {
            arr3->A[arr3->length++] = arr1->A[i];
        }
    }
    return arr3;
}

// finding missing elements for n natural numbers starting from 1-n using formula
int missingEleNat(struct Array *arr){
   int n = Max(*arr);
   
   int sum = 0;
   int s = (n*(n+1))/2;
   for(int i=0; i<arr->length; i++){
    sum += arr->A[i];
   }
   s = s-sum;

   return s;
}

// finding missing elements for n natural numbers starting from m-n using indices
void missingEleNat1(struct Array *arr){
    int l=arr->A[0];
    int h=Max(*arr);
    int diff=l-0;
    for(int i=0; i<arr->length; i++){
        if(arr->A[i]-i != diff){
            cout<<i+diff<<" is a missing element"<<endl;
            break;
        }
    }
}

// finding multiple missing elements
void multiMissingEle(struct Array *arr){
    int l=arr->A[0];
    int diff=l-0;
    for(int i=0; i<arr->length; i++){
        if(arr->A[i]-i != diff){
            while(diff<arr->A[i]-i){
                cout<<i+diff<<" is a missing element"<<endl;
                diff++;
            }
        }
    }
}

// finding missing elements using hash table n natural numbers
void multiMissingEleHash(struct Array *arr){
    int h = Max(*arr)+1;
    int *H = new int[h];
    for(int i=0; i<h; i++) H[i]=0;
    for(int i=0; i<arr->length; i++){
        H[arr->A[i]]+=1;
    }
    for(int i=1; i<h; i++){
        if(H[i]==0){
            cout<<i<<" is a missing element"<<endl;
        }
    }
}

// finding duplicates in sorted array
void duplicatesSort(struct Array *arr){
    int lastDup=0;
    for(int i=0; i<arr->length-1; i++){
        if(arr->A[i]==arr->A[i+1] && arr->A[i]!=lastDup ){
            cout<<arr->A[i]<<" ";
            lastDup=arr->A[i];
        }
    }
}

// finding, counting number of duplicates in sorted array 
void duplicatesCountSort(struct Array *arr){
    int i,j;
    for(i=0; i<arr->length-1; i++){
        if(arr->A[i]==arr->A[i+1]){
            j=i+1;
            while(arr->A[j]==arr->A[i]){
                j++;
            }
            cout<<arr->A[i]<<" is appearing "<<j-i<<" times"<<endl;
            i=j-1;
        }
    }
}

// finding duplicates elements in Array using hash table
void duplicatesHash(struct Array *arr){
    int h=Max(*arr);
    int *H = new int[h];
    for(int i=1;i<=h;i++) H[i]=0;
    for(int i=0; i<arr->length; i++){
        H[arr->A[i]]+=1;
    }

    for(int i=1; i<=h; i++){
        if(H[i]>1){
            cout<<i<<" is appearing "<<H[i]<<" times"<<endl;
        }
    }
}

// finding, counting number of duplicates in un-sorted array
void duplicatesUnSort(struct Array *arr){
    int i,j,count;
    for(i=0;i<arr->length-1;i++){
        count=0;
        for(j=i+1;j<arr->length;j++){
            if(arr->A[i]==arr->A[j] && arr->A[i]!=-1){
                arr->A[j]=-1;
                count++;
            }
        }
        if(count>0){
            cout<<arr->A[i]<<" is appearing "<<count<<" times"<<endl;
        }
    }
}

// find a pair with sum k (two sum prob)
void twoSum(struct Array *arr, int k){
    int i,j;
    for(i=0; i<arr->length-1;i++){
        for(j=i+1; j<arr->length;j++){
            if(arr->A[i]+arr->A[j]==k){
                cout<<arr->A[i]<<" + "<<arr->A[j]<<" = "<<k<<endl;
            }
        }
    }
}

// find a pair with sum k (two sum prob) using Hash table
void twoSumHash(struct Array *arr, int k){
    int h=Max(*arr);
    int H[h]={0};
    for(int i=0;i<arr->length;i++){
        if(H[arr->A[i]-k]!=0){
            cout<<k-arr->A[i]<<" + "<<arr->A[i]<<" = "<<k<<endl;
        }
    }
}

// find a pair with sum k for sorted array
void twoSumSort(struct Array *arr,int k){
    int i=0, j=arr->length-1;
    while(i<j){
        if(arr->A[i]+arr->A[j]==k){
            cout<<arr->A[i]<<" + "<<arr->A[j]<<" = "<<k<<endl;
            i++;j--;
        }
        else if(arr->A[i]+arr->A[j]<k){
            i++;
        } else{
            j--;
        }
    }
}

// find max and min in a single scan
void MinMax(struct Array *arr){
    int i,min,max;
    min=max=arr->A[0];
    for(i=1; i<arr->length; i++){
        if(arr->A[i]<min){
            min=arr->A[i];
        } else if(arr->A[i]>max){
            max=arr->A[i];
        }
    }
    cout<<"Min :"<<min<<"\nMax: "<<max<<endl;
}

int main(){
    // struct Array arr={{-2,-3,4,5,-6,10,-23,-15},20,8};
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
    // Rearrange(&arr);

    // struct Array arr1={{2,10,9,15,25},10,5};
    // struct Array arr2={{10,5,7,15,18},10,5};
    // struct Array *arr3 = Merge(&arr1, &arr2);
    // struct Array *arr3 = Union(&arr1, &arr2);
    // struct Array *arr3 = Intersection(&arr1, &arr2);
    // struct Array *arr3 = Difference(&arr1, &arr2);
    // struct Array *arr3 = UnSortDiff(&arr1, &arr2);
    struct Array arr1={{1,2,3,4,5,7,8,10,12,13},10,10};
    // cout<<missingEleNat(&arr1);
    // struct Array arr = {{3,6,8,8,7,12,15,15,15},10,10};
    // multiMissingEleHash(&arr);
    // duplicatesSort(&arr);
    // duplicatesCountSort(&arr);
    // duplicatesUnSort(&arr);
    // struct Array arr = {{6,3,8,10,16,7,5,2,0,14},10,10};
    // twoSum(&arr, 8);
    // twoSumHash(&arr, 8);
    // twoSumSort(&arr1, 8);
    MinMax(&arr1);

    // display(*arr3);

    return 0;
}
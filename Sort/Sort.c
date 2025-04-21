#include<stdio.h>

// Swap
void Swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Bubble sort impl
void BubbleSort(int A[], int n){
    int flag; // adaptive
    for(int i=0; i<n-1; i++){
        flag=0;
        for(int j=0; j<n-i-1; j++){
            if(A[j]>A[j+1]){
                Swap(&A[j], &A[j+1]);
                flag=1;
            }
        }
        if(flag==0) break;
    }
}

// Insertion sort 
void InsertionSort(int A[], int n){
    int i,j,x;
    for(i=1; i<n; i++){
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

// Selection Sort
void SelectionSort(int A[], int n){
    int i, j, k;
    for(i=0; i<n-1; i++){
        for(j=k=i; j<n; j++){
            if(A[j]<A[k]){
                k=j;
            }
        }
        Swap(&A[i], &A[k]);
    }
}

// Quick Sort
// Paritioning
int Partition(int A[], int l, int h){
    int pivot = A[l];
    int i=A[l], j=A[h];

    do{
        do{i++;}while(A[i]<=A[j]);
        do{j--;}while(A[j]>pivot);
        if(i<j) Swap(&A[i], &A[j]);
    }while(i<j);
    Swap(&A[l], &A[j]);
    return j;
}

int main(){
    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(A)/sizeof(A[0]);
    // BubbleSort(A, n);
    // InsertionSort(A, n);
    SelectionSort(A, n);

    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }

    return 0;
}
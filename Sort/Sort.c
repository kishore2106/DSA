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

int main(){
    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(A)/sizeof(A[0]);
    // BubbleSort(A, n);
    InsertionSort(A, n);

    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }

    return 0;
}
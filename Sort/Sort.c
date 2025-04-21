#include<stdio.h>

// Swap
void Swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Bubble sort impl
void BubbleSort(int A[], int n){
    int flag;
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

int main(){
    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(A)/sizeof(A[0]);
    BubbleSort(A, n);

    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }

    return 0;
}
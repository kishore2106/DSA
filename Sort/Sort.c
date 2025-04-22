#include<stdio.h>
#include<stdlib.h>

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
    int i=l, j=h;

    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j) Swap(&A[i], &A[j]);
    }while(i<j);
    Swap(&A[l], &A[j]);
    return j;
}

// Quick Sort Recursive
void QuickSort(int A[], int l, int h){
    int j;
    if(l<h){
        j=Partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j+1, h);
    }
}

// Merge Sort
// Merge Impl
void Merge(int A[], int l, int mid, int h){
    int i=l,j=mid+1,k=l;
    int B[100];
    
    while(i<=mid && j<=h){
        if(A[i]<A[j])
            B[k++]=A[i++];
        else 
            B[k++]=A[j++];
    }
    for(;i<=mid;i++){
        B[k++]=A[i];
    }
    for(;j<=h;j++){
        B[k++]=A[j];
    }
    for(i=l; i<=h; i++){
        A[i]=B[i];
    }
}

// Merge Sort Impl Iterative
void IMergeSort(int A[], int n){
    int i,l,h,mid,p;
    for(p=2; p<=n; p=p*2){
        for(i=0; p+i-1<n; i=p+i){
            l=i;
            h=p+i-1;
            mid=(l+h)/2;
            Merge(A, l, mid, h);
        }
    }
    if(p/2<n){
        Merge(A, 0, p/2-1, n);
    }
}

// Merge Sort Impl Recurisve
void RMergeSort(int A[], int l, int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        RMergeSort(A, l, mid);
        RMergeSort(A, mid+1, h);
        Merge(A, l, mid, h);
    }
}

// Max of an Array
int MaxArray(int A[], int n){
    int max=A[0];
    for(int i=1; i<n; i++){
        if(A[i]>max){
            max=A[i];
        }
    }
    return max;

}

// Count Sort
void CountSort(int A[], int n){
    int max;
    int i,j;
    int *c;
    max=MaxArray(A, n);
    c=(int*)malloc((max+1)*sizeof(int));
    for(i=0; i<max+1; i++) c[i]=0;
    for(i=0; i<n; i++) c[A[i]]++;
    i=j=0;
    while(j<max+1){
        if(c[j]>0){
            A[i++]=j;
            c[j]--;
        } else{
            j++;
        }
    }
    
}

int main(){
    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(A)/sizeof(A[0]);
    // BubbleSort(A, n);
    // InsertionSort(A, n);
    // SelectionSort(A, n);
    // int A[] = {64, 34, 25, 12, 22, 11, 90, __INT32_MAX__};
    // QuickSort(A, 0, 7);
    // IMergeSort(A, n);
    // RMergeSort(A, 0, n-1);

    // for(int i=0; i<n; i++){
    //     printf("%d ", A[i]);
    // }
    // printf("Max :%d",MaxArray(A, n));
    CountSort(A, n);
    
    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }

    return 0;
}
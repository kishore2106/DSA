// 3 methods to create 2 dimensional array

#include<iostream>
#include<stdlib.h>
using namespace std;

int main() {
    // memory is created in Stack
    int A[3][4] = {{1,2,3,4}, {2,4,6,8}, {3,5,7,9}};

    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++){
            cout << A[i][j] << " ";
        }
        cout<<endl;
    }

    int *B[3]; // Array of pointers is created in stack (row)
    B[0] = new int[4]; // memory is created in Heap
    B[1] = new int[4]; // memory is created in Heap
    B[2] = new int[4]; // memory is created in Heap

    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++){
            cout << B[i][j] << " ";
        }
        cout<<endl;
    }

    int **C; // pointer to pointer is created in stack
    C = (int **)malloc(3*sizeof(int *)); // memory is created in Heap
    C[0] = (int *)malloc(4*sizeof(int)); // memory is created in Heap
    C[1] = (int *)malloc(4*sizeof(int)); // memory is created in Heap
    C[2] = (int *)malloc(4*sizeof(int)); // memory is created in Heap
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++){
            cout << C[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;
}
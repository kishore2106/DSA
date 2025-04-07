// Declaration and Intialization for Array

#include<iostream>
using namespace std;

int main() {

    int A[5]; // garbage values will be assigned
    int B[5] = {2, 4, 6, 8, 10}; // decl and init
    int C[10] = {2, 5, 6}; // decl and init, rest will be assigned to 0
    int D[5] = {0}; // all values will be 0
    int E[] = {2, 3, 4, 5}; // size of array is based on the number of elements init

    // Length of Array
    int n = sizeof(A) / sizeof(A[0]);

    // printing address of array A
    for (int i=0; i<n; i++){
        cout<<&A[i]<<endl;
    }

    return 0;
}
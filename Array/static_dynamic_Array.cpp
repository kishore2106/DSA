// Static vs Dynamic Array

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main() {
    int A[5] = {1,2,3,4,5};
    int *p, *p1;

    p = (int *)malloc(5*sizeof(int)); // Dynamic in C
    p[0] = 8;
    p[1] = 3;
    p[2] = 5;
    p[3] = 6;
    p[4] = 2;

    p1 = new int[5]; // Dynamic in C++
    p1[0] = 23;
    p1[1] = 52;
    p1[2] = 26;
    p1[3] = 95;
    p1[4] = 56;

    for(int i=0; i<5; i++) {
        cout<<A[i]<<" ";
    }
    cout<<"\n";

    for(int i=0; i<5; i++) {
        cout<<p[i]<<" ";
    }
    cout<<"\n";

    for(int i=0; i<5; i++) {
        cout<<p1[i]<<" ";
    }
    cout<<"\n";

    return 0;
}
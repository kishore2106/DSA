// Heap Impl using array and vector

#include<iostream>
#include<vector>
using namespace std;

// Inserting an element in Heap
void InsertA(int A[], int n){
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2]){
        A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    A[i] = temp;
}

// STL vector based
void Insert(vector<int>& vec, int key){
    // Insert key at the end
    auto i = vec.size();
    vec.emplace_back(key);
 
    // Rearrange elements: Indices are not DRY :-(
    while (i > 0 && key > vec[i % 2 == 0 ? (i/2)-1 : i/2]){
        vec[i] = vec[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    vec[i] = key;
}

int main(){

    return 0;
}
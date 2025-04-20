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

// printing heap
template <class T>
void Print(T& vec, int n){
    cout << "Max Heap: [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

template <class T>
void Print(T& vec, int n, char c){
    cout << c << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

//Create Heap
void createHeap(int A[], int n){
    for (int i=0; i<n; i++){
        InsertA(A, i);
    }
}

//Create Heap using vector
void CreateHeap(vector<int>& vec, int A[], int n){
    // O(n log n)
    for (int i=0; i<n; i++){
        Insert(vec, A[i]);
    }
}

void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

// Heapify fastest method to create a max heap
void Heapify(int A[], int n){
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i=(n/2)-1; i>=0; i--){
 
        int j = 2 * i + 1;  // Left child for current i
 
        while(j < n-1){
            // Compare left and right children of current i
            if (A[j] < A[j+1]){
                j = j+1;
            }
 
            // Compare parent and largest child
            if (A[i] < A[j]){
                swap(A, i, j);
                i = j;
                j = 2 * i + 1;
            } else {
                break;
            }
        }
    }
}

int main(){

    // int a[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};
    // InsertA(a, 9);
    // Print(a, sizeof(a)/sizeof(a[0]));
    // cout << endl;
 
    // // STL based
    // vector<int> v = {45, 35, 15, 30, 10, 12, 6, 5, 20};
    // Print(v, v.size());
    // v.reserve(15);  // Reserve space for 15 elements
 
    // Insert(v, 50);
    // Print(v, v.size());

    // cout << "Create Heap" << endl;
    // int b[] = {10, 20, 30, 25, 5, 40, 35};
    // Print(b, sizeof(b)/sizeof(b[0]), 'b');

    // vector<int> v;
    // CreateHeap(v, b, sizeof(b)/sizeof(b[0]));
    // Print(v, v.size(), 'v');
 
    // cout << "Inplace Insert" << endl;
    // createHeap(b, sizeof(b)/sizeof(b[0]));
    // Print(b, sizeof(b)/sizeof(b[0]), 'b');

    int A[] = {5, 10, 30, 20, 35, 40, 15};
    Print(A, sizeof(A)/sizeof(A[0]), "A");
 
    Heapify(A, sizeof(A)/sizeof(A[0]));
    Print(A, sizeof(A)/sizeof(A[0]), "Heapified A");
    cout << endl;
 
    int B[] = {5, 10, 30, 20};
    Print(B, sizeof(B)/sizeof(B[0]), "B");
 
    Heapify(B, sizeof(B)/sizeof(B[0]));
    Print(B, sizeof(B)/sizeof(B[0]), "Heapified B");
 
    return 0;
}
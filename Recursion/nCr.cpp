// Combination formula using Recursion

#include<iostream>
using namespace std;

// Iterative
int fact(int n){
    if(n == 0) return 1;
    return n * fact(n-1);
}

int nCr(int n, int r){
    int num, den;
    num = fact(n);
    den = fact(r) * fact(n-r);
    return num / den;
}

// Recursion
int NCR(int n, int r) {
    if(n == r || r == 0) return 1;
    return (NCR(n-1, r-1) + NCR(n-1, r));
}

int main(){

    cout<<nCr(4, 2)<<endl;
    cout<<NCR(4, 2)<<endl;
    return 0;
}
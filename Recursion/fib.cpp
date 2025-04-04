// Fibonacci series using Recursion with Memoiztion

#include<iostream>
using namespace std;

// Iterative 
int fib(int n) {
    int t0 = 0, t1 = 1, s = 0;
    for (int i=2; i<=n; i++) {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

// Recursion
int rfib(int n) {
    if (n <= 1) return n;
    return rfib(n-2)+rfib(n-1);
}

// Recursion with memoization
int f[10];
int mfib(int n) {
    if(n<=1){
        f[n] = n;
        return n;
    } else {
        if(f[n-2] == -1)
            f[n-2] = mfib(n-2);
        if(f[n-1] == -1)
            f[n-1] = mfib(n-1);
        f[n] = f[n-2] + f[n-1];
        return f[n];
    }
}


int main(){
    for(int i=0; i<10; i++){
        f[i] = -1;
    }
    cout<<fib(6)<<endl;
    cout<<rfib(6)<<endl;
    cout<<mfib(6)<<endl;
    return 0;
}
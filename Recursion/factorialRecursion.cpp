// Factorial of a number using Recursion

#include<iostream>
using namespace std;

int fact(int n) {
    if (n < 0) return (0);
    if (n == 0){
        return 1;
    } else {
        return fact(n - 1) * n;
    }
}

int Ifact(int n) {
    int fact = 1;
    for (int i=1; i<=n; i++){
        fact = fact * i;
    }
    return fact;
}

int main() {
    cout<<fact(5)<<endl;
    cout<<Ifact(5)<<endl;
    return 0;
}
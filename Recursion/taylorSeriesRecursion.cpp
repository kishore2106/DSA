// Taylor Series using Recursion [1 + x/1 + x^2/2! + x^3/3! + ....... + n terms]

#include<iostream>
using namespace std;

double e(int x, int n) {
    static int p = 1, f = 1;
    double r;
    if (n == 0) {
        return 1;
    } else {
        r = e(x, n-1);
        p = p * x;
        f = f * n;
        return r + p/f;
    }
}


int main() {
    cout<<e(2, 4)<<endl;
    return 0;
}
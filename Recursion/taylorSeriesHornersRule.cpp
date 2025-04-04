// Taylor Series using Recursion using Horner's Rule to reduce the number of multiplication [1 + x/1 + x^2/2! + x^3/3! + ....... + n terms]

#include<iostream>
using namespace std;

// Recursion
double e(int x, int n) {
    static double s;
    if (n == 0) {
        return s;
    } else {
        s = 1 + x* s/n;
        return e(x, n-1);
    }
}

// Loop
double Ie(int x, int n) {
    // double s = 1;
    // for ( n ; n > 0; n --) {
    //     s = 1 + x* s/n;
    // }
    // return s;

    double s = 1;
    int i;
    double num = 1, den = 1;

    for (i=1; i<=n; i++) {
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}

int main() {
    cout<<e(2, 10)<<endl;
    cout<<Ie(2, 10)<<endl;
    return 0;
}
// Sum of n natural numbers using Recursion

#include<iostream>
using namespace std;

// int sum(int n) {
//     if (n > 0) {
//         return sum(n-1) + n;
//     }
//     return 0;
// }

int sum(int n) {
    if (n == 0) {
        return 0;
    }
    return sum(n - 1) + n;
}

int Isum(int n) {
    int s = 0;
    int i;
    for(i=1; i<=n; i++) {
        s = s + i;
    }
    return s;
}

int main() {

    int n = 5;
    cout<<sum(n)<<endl;
    cout<<Isum(n)<<endl;
    return 0;
}